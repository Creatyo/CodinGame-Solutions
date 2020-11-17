using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Solution
{
    static void Main(string[] args)
    {
        List<double> LON_D = new List<double>();
        List<double> LAT_D = new List<double>();

        int it;
        string tmp;

        List<string> Name = new List<string>();

        double x, y;
        List<double> Distance = new List<double>();

        string DestName;
        double min = 10000;
        int id = 0;
        
        string LON = Console.ReadLine();
        string LAT = Console.ReadLine();
        LON = LON.Replace(',', '.');
        LAT = LAT.Replace(',', '.');
        double LON_U = Convert.ToDouble(LON) * Math.PI / 180;
        double LAT_U = Convert.ToDouble(LAT) * Math.PI / 180;

        int N = int.Parse(Console.ReadLine());
        for (int i = 0; i < N; i++)
        {
            string DEFIB = Console.ReadLine();
            //Erase first number
            it = DEFIB.IndexOf(';');
            DEFIB = DEFIB.Remove(0,it+1);
            //Extraction and erase name location
            it = DEFIB.IndexOf(';');
            Name.Add(DEFIB.Substring(0,it));
            DEFIB = DEFIB.Remove(0,it+1);
            //Erase adress
            it = DEFIB.IndexOf(';');
            DEFIB = DEFIB.Remove(0,it+1);
            it = DEFIB.IndexOf(';');
            DEFIB = DEFIB.Remove(0,it+1);
            //Extraction longitude and erase it
            it = DEFIB.IndexOf(';');
            tmp = DEFIB.Substring(0,it);
            tmp = tmp.Replace(',', '.');
            LON_D.Add(Convert.ToDouble(tmp) * Math.PI / 180);
            DEFIB = DEFIB.Remove(0,it+1);
            //Extraction latitude and erase it
            DEFIB = DEFIB.Replace(',', '.');
            LAT_D.Add(Convert.ToDouble(DEFIB) * Math.PI / 180);
            //Calculate distance and search the nearess
            x = (LON_D[i] - LON_U) * Math.Cos((LON_D[i] + LON_U)/2);
            y = (LAT_D[i] - LAT_U);
            Distance.Add(Math.Sqrt(Math.Pow(x,2)+Math.Pow(y,2))*6371);
            if(Distance[i] < min)
            {
                min = Distance[i];
                id = i;
            }
        }

        DestName = Name[id];

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine(DestName);
    }
}