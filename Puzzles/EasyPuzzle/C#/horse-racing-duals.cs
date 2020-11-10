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
        int N = int.Parse(Console.ReadLine());
        int Diff = 10000000;
        int[] p = new int[N];
        
        for (int i = 0; i < N; i++)
        {
            p[i] = int.Parse(Console.ReadLine());
            
        }
        
        Array.Sort(p);

        for (int i = 0; i < N-1; i++)
        {
            if(p[i+1] - p[i] < Diff)
            {
                Diff = p[i+1] - p[i];
            }
        }

        // Write an action using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine(Diff);
    }
}