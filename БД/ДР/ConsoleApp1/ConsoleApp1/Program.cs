using System;
using System.Data;
using lcpi.data.oledb;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            var cn = new OleDbConnection("file name=D:\\3 курс 1 семестр\\БД\\ДР\\test.udl");//создаем объект подключения базы данных
            
            string command = "";
            bool flag = false;
            while (!flag) { 
                Console.WriteLine("Menu");
                Console.WriteLine("0.Exit");
                Console.WriteLine("1.Select");
                Console.WriteLine("2.Insert");
                Console.WriteLine("3.Delete");
                
                Console.WriteLine("Input comand: ");
                
                int num = int.Parse((Console.ReadLine()));
                switch (num) {
                    case 0:
                        flag = true;
                        break;
                    case 1:
                        command = "Select";
                        Select(command,cn);
                        

                        break;
                    case 2:
                        command = "Insert";
                        Insert(command, cn);
                        
                        
                        break;
                    case 3:
                        command = "Delet";
                        Delete(command, cn);
                        
                        break;
                    default:
                        Console.WriteLine("input 1-3");
                        break;

                }
            }

        }
        static void Select(string command, OleDbConnection cn)
        {
            cn.Open();//выполняем подключение
            var tr = cn.BeginTransaction();//выполняет начало транзакций 
            Console.Write("Type columns: 1.String or 2.Integer   ");
            int num = int.Parse(Console.ReadLine());
            bool flag = false;
            switch (num)
            {
                case 1:
                    flag = false;
                    break;
                case 2:
                    flag = true;
                    break;
            }
            Console.Write("Column: ");
            string pole = Console.ReadLine();
            Console.Write("From: ");
            string from = Console.ReadLine();
            string sql = command + " " + pole + " from " + from;
            var cmd = new OleDbCommand(sql, cn, tr);
            var reader = cmd.ExecuteReader();
            int n = 0;
            while (reader.Read())
            {
                ++n;
                if (n > 1)
                    Console.Write(", ");
                if(!flag)
                    Console.Write("{0}", reader.GetString(0));//выводит зачения
                else
                    Console.Write("{0}", reader.GetInt64(0));//выводит зачения
            }
            Console.WriteLine("");
            tr.Commit();
            cn.Close();
        }

        static void Insert(string command, OleDbConnection cn)
        {
            cn.Open();//выполняем подключение
            var tr = cn.BeginTransaction();//выполняет начало транзакций 
            Console.Write("Есть ли поля для ввода? 0.Нет 1.Да");
            int num = int.Parse(Console.ReadLine());
            string pole="";
            switch (num)
            {
                case 0:
                    pole = "";
                    break;
                case 1:
                    Console.Write("Pole: ");
                    pole = "(" + Console.ReadLine() + ")";
                    break;


            }
            
            Console.Write("Into: ");
            string into = Console.ReadLine();
            Console.Write("Values: ");
            string values = Console.ReadLine();
            string sql = command + " into " + into +" "+ pole +" values("+values+");" ;
            
            var cmd = new OleDbCommand(sql, cn, tr);
            
            Console.WriteLine("RecordsAffected: {0}",cmd.ExecuteNonQuery());
            tr.Commit();
            cn.Close();

        }

        static void Delete(string command, OleDbConnection cn)
        {
            cn.Open();//выполняем подключение

            var tr = cn.BeginTransaction();//выполняет начало транзакций 
            Console.Write("Column: ");
            string pole = Console.ReadLine();
            Console.Write("Table: ");
            string from = Console.ReadLine();
            string sql = "Alter Table " + from+" Drop column " + pole;
            var cmd = new OleDbCommand(sql, cn, tr);

            Console.WriteLine("RecordsAffected: {0}", cmd.ExecuteNonQuery());
            tr.Commit();
            cn.Close();
        }
    }
}
