using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
 
namespace Server
{
    class Program
    {
        static int port = 8005;
        static void Main(string[] args)
        {
            IPEndPoint ipPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), port);
            
            Socket listenSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            try
            {
                listenSocket.Bind(ipPoint);
                listenSocket.Listen(10);
                Console.WriteLine("Сервер запущен. Ожидание подключений...");
                while (true)
                {
                    Socket handler = listenSocket.Accept();
                    StringBuilder builder = new StringBuilder();
                    int bytes = 0;
                    byte[] data = new byte[256];
                    do
                    {
                        bytes = handler.Receive(data);
                        builder.Append(Encoding.Unicode.GetString(data, 0, bytes));
                    }
                    while (handler.Available>0);

                    string input = builder.ToString();
                    string message;
                    if (input == "Hello")
                    {
                        message = "Hello!";
                    }
                    else if (input == "Music")
                    {
                        message = "Buy license!";
                    }
                    else
                    {
                        message = "WHY ARE YOU RUNNING?";
                    }
                    data = Encoding.Unicode.GetBytes(message);
                    handler.Send(data);
                    handler.Shutdown(SocketShutdown.Both);
                    handler.Close();
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}