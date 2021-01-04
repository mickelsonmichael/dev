using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Host
{
    public static class HostService
    {
        public static void ListenForClient()
        {
            var hostName = Dns.GetHostName();
            var ipHostEntry = Dns.GetHostEntry(hostName);
            var ipAddress = ipHostEntry.AddressList[0];
            var endpoint = new IPEndPoint(ipAddress, 11111);

            var socket = new Socket(ipAddress.AddressFamily,
                                        SocketType.Stream,
                                        ProtocolType.Tcp);
            
            socket.Bind(endpoint);
            socket.Listen(2);

            Console.WriteLine("Waiting for connections...");
            
            var sender = socket.Accept();

            var bytes = new byte[1024];
            int numByte = sender.Receive(bytes); 
            
            var thisString = Encoding.ASCII.GetString(bytes, 0, numByte);

            Console.WriteLine($"Client said: {thisString}");

            var confirmationMessage = Encoding.ASCII.GetBytes("Message received");

            sender.Send(confirmationMessage);

            sender.Shutdown(SocketShutdown.Both);
            sender.Close();
        }
    }
}