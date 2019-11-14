using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace SQLClient
{
    class Program
    {
        static int port = 8080;

        static string address = "127.0.0.1";
        static void Main(string[] args)
        {
            //System.Text.UnicodeEncoding encoding = new System.Text.UnicodeEncoding();



            try
            {
                IPEndPoint ipPoint = new IPEndPoint(IPAddress.Parse(address), port);

                Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                string quest = "Y";

                while (quest == "Y" || quest == "y")
                {

                    socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                    socket.Connect(ipPoint);

                    Console.Write("Введите запрос к БД: ");
                    string query = Console.ReadLine();

                    byte[] data = new byte[8192];
                    data = System.Text.Encoding.UTF8.GetBytes(query);
                    socket.Send(data);
                    Console.WriteLine("Команда " + query + " отправлена");

                    /*StringBuilder builder = new StringBuilder();
                    int bytes = 0;

                    do
                    {
                        bytes = socket.Receive(data);
                        builder.Append(Encoding.Unicode.GetString(data, 0, bytes));
                    }
                    while (socket.Available > 0);*/
                    data = new byte[8192];
                    socket.Receive(data);

                    query = Encoding.UTF8.GetString(data.Where(x => x != 0).ToArray());

                    Console.WriteLine(DateTime.Now.ToShortTimeString() + ": " + query);

                    // Соединение необходимо закрыть
                    Console.WriteLine("Закрытие соединения");
                    socket.Shutdown(SocketShutdown.Both);
                    socket.Close();

                    Console.WriteLine("Введите Y/y для отправки нового запроса, другой символ - для выхода...");
                    quest = Console.ReadLine();
                }

            }
            catch (Exception e)
            {
                Console.WriteLine("Произошла ошибка: {0}", e.ToString());
            }
        }
    }
}