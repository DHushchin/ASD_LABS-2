using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Lab_7
{
    public class FilesProcessing
    {
        public static void Segments()
        {
            int length = 204800;
            List<int> chunk = new List<int>();
            int totalLength = 0;
            int index1 = 0;
            int index2 = 0;
            using StreamWriter writer = new StreamWriter(Directory.GetCurrentDirectory() + @"\res" + ".txt");
            using StreamReader reader = new StreamReader(Directory.GetCurrentDirectory() + @"\10Mb" + ".txt");
            string numberString;
            List<int> numberOfValue = new List<int>();
            while ((numberString = reader.ReadLine()) != null)
            {
                List<int> numbers = numberString.Split(' ').Where(x => x != "").Select(x => int.Parse(x)).ToList();
                numberOfValue.Add(numbers.Count);
                foreach (int number in numbers)
                    chunk.Add(number);
               
                totalLength++;
                if (totalLength % length == 0)
                {
                    chunk.Sort();
                    index1 = 0;
                    index2 = 0;
                    for (int i = 0; i < numberOfValue.Count; i++)
                    {
                        index2 += numberOfValue[i];
                        for (int j = index1; j < index2; j++)
                            writer.Write(chunk[j].ToString() + " ");
                        index1 += numberOfValue[i];
                        writer.WriteLine();
                    }
                    chunk.Clear();
                    numberOfValue = new List<int>();
                }
            }
            chunk.Sort();
            index1 = 0;
            index2 = 0;
            for (int i = 0; i < numberOfValue.Count; i++)
            {
                index2 += numberOfValue[i];
                for (int j = index1; j < index2; j++)
                    writer.Write(chunk[j].ToString() + " ");
                index1 += numberOfValue[i];
                writer.WriteLine();
            }
        }
        public static void Sort(string path, string name)
        {
            using StreamReader reader = new StreamReader(path + name + ".txt");
            using StreamWriter writer0 = new StreamWriter(path + name + "0" + ".txt");
            using StreamWriter writer1 = new StreamWriter(path + name + "1" + ".txt");
            using StreamWriter writer2 = new StreamWriter(path + name + "2" + ".txt");
            while (!reader.EndOfStream)
            {
                string a = reader.ReadLine();
                int temp = 0;
                int index = 0;
                int[] numbers = a.Split(' ').Where(x => x != "").Select(x => int.Parse(x)).ToArray();
                while (index < numbers.Length - 1)
                {
                    writer0.Write(numbers[index] + " ");
                    for (int i = index + 1; i < numbers.Length; i++)
                    {
                        if (numbers[i - 1] <= numbers[i])
                        {
                            writer0.Write(numbers[i] + " ");
                            if (i == numbers.Length - 1)
                            {
                                index = i;
                            }
                        }
                        else
                        {
                            temp = numbers[i];
                            index = i;
                            break;
                        }
                    }
                    writer1.Write(temp + " ");
                    for (int i = index + 1; i < numbers.Length; i++)
                    {
                        if (numbers[i - 1] <= numbers[i])
                        {
                            writer1.Write(numbers[i] + " ");
                            if (i == numbers.Length - 1)
                            {
                                index = i;
                            }
                        }
                        else
                        {
                            temp = numbers[i];
                            index = i;
                            break;
                        }
                    }
                    writer2.Write(temp + " ");
                    for (int i = index + 1; i < numbers.Length; i++)
                    {
                        if (numbers[i - 1] <= numbers[i])
                        {
                            writer2.Write(numbers[i] + " ");
                            if (i == numbers.Length - 1)
                            {
                                index = i;
                            }
                        }
                        else
                        {
                            temp = numbers[i];
                            index = i;
                            break;
                        }
                    }
                }
            }
        }
    }
}
