using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Client
{
    public static class ClientService
    {
        public static void DoClient()
        {
            var hostname = Dns.GetHostName();

            IPHostEntry ipHost = Dns.GetHostEntry(hostname);
            IPAddress ipAddr = ipHost.AddressList[0]; 
            IPEndPoint localEndPoint = new IPEndPoint(ipAddr, 11111);

            var socket = new Socket(ipAddr.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            socket.Connect(localEndPoint);

            Console.WriteLine($"Socket connected to -> {socket.RemoteEndPoint} "); 

            var toSend = Encoding.ASCII.GetBytes("Hello World!");

            var numSent = socket.Send(toSend);

            var incoming = new byte[1024];
            var recievedBytes = socket.Receive(incoming);

            var incomingMessage = Encoding.ASCII.GetString(incoming);

            Console.WriteLine($"Server says: {incomingMessage}");

            socket.Shutdown(SocketShutdown.Both);
            socket.Close();
        }
    }
}