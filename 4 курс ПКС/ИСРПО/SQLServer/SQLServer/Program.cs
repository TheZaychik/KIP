using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
using MySql.Data.MySqlClient;
using System.Linq;
using System.Data.Sql;

namespace SQLServer
{
    class Program
    {
        public static void Main(string[] args)
        {
            //System.Text.UnicodeEncoding encoding = new System.Text.UnicodeEncoding();

            string connStr = "server=localhost;user=root;database=test;password=root;";
            MySqlConnection dbConnection = new MySqlConnection(connStr);

            dbConnection.Open();

            try
            {
                IPAddress localAddress = IPAddress.Parse("127.0.0.1");

                Socket listenSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                IPEndPoint ipEndpoint = new IPEndPoint(localAddress, 8080);

                listenSocket.Bind(ipEndpoint);

                listenSocket.Listen(1);
                string quest = "Y";
                // Начинаем ждать соединение – бесконечный цикл
                while (quest == "Y" || quest == "y")
                {
                    Console.WriteLine("Сервер ожидает {0}", ipEndpoint);

                    // Программа приостановлена. Ожидаем входящего соединения
                    // Это синхронное TCP приложение
                    Socket handler = listenSocket.Accept();

                    //Входящее соединение необходимо обработать
                    Console.WriteLine("Принято соединение от {0}", handler.RemoteEndPoint);

                    //принятие сообщения
                    byte[] data = new byte[8192];
                    string req = null;
                    handler.Receive(data);

                    string sqlQuery = Encoding.Default.GetString(data.Where(x => x != 0).ToArray());
                    data = new byte[8192];
                    if (sqlQuery.Contains("UPDATE") || sqlQuery.Contains("DELETE") || sqlQuery.Contains("INSERT"))
                    {
                        Console.WriteLine(DateTime.Now.ToShortTimeString() + ":" + sqlQuery);
                        
                        //Выполняем команду в базе данных
                        using (MySqlCommand command = new MySqlCommand(sqlQuery, dbConnection))
                        {
                            //Отправляем команду
                            try
                            {
                                int number = command.ExecuteNonQuery();
                                Console.WriteLine("Затронуто строк: " + number);
                                req = "Затронуто строк: " + number;
                            }
                            catch (MySqlException ex)
                            {
                                Console.WriteLine("Ошибка: " + ex.Message);
                                req = "Ошибка: " + ex.Message;
                            }
                            
                            handler.Send(Encoding.UTF8.GetBytes(req));
                        }


                    }
                    else
                    {
                        Console.WriteLine("Команда не распознана");
                    }

                    handler.Shutdown(SocketShutdown.Both);
                    handler.Close();

                    // Соединение необходимо закрыть
                    Console.WriteLine("Закрытие соединение");
                    handler.Close();

                    Console.WriteLine("Введите Y/y для продолжения работы сервера, другой символ - для остановки...");
                    quest = Console.ReadLine();
                }

            }
            catch (Exception e)
            {
                Console.WriteLine("Произошла ошибка: {0}", e.ToString());
            }
            Console.WriteLine("Server was stopped");
            Console.ReadKey();
        }
    }
}