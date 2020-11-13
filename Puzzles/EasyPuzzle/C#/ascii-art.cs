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
        int L = int.Parse(Console.ReadLine());
        int H = int.Parse(Console.ReadLine());
        string T = Console.ReadLine();
        T = T.ToUpper();
        string answer = "";
        for (int i = 0; i < H; i++)
        {
            string ROW = Console.ReadLine();
                
            for(int l = 0; l < T.Length; l++)
            {
                int value;
                if(((int)(T[l])<65)||(((int)(T[l])>91)))
                {
                    value = 26;
                }
                else
                {
                   value = (int)(T[l]) - 65;
                }
                for (int j = L*value; j < L*(value+1); j++)
                {
                    answer += ROW[j];
                }
                
            }
            answer += "\n";
        }

        // Write an action using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine(answer);
    }
}