using System;
using System.Net.Http;
using System.Threading.Tasks;

public class Program
{
    public static void Main(String[] args)
    {
        HttpClient client = new HttpClient();
        try
        {
        	var handle = client.GetStringAsync("http://183.63.251.70/SingleWindow/SingleWindowMessageService.svc/json/");
        	handle.Wait();
        	Console.WriteLine(handle.Result);
        }
        catch(HttpRequestException e)
        {
        	Console.WriteLine("\nException Caught!");
        	Console.WriteLine("Message: {0}",e.Message);
        }
        client.Dispose();
    }
}