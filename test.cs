// 네임스페이스를 만들어줘
namespace test
{
    // 클래스를 만들어줘
    class Program
    {
        // 메인함수를 만들어줘
        static void Main(string[] args)
        {
            // 콘솔에 출력해줘
            Console.WriteLine("Hello World!");



            
            class plusMath(int a, b){
                return a+b;
            }
            class minusMath(int a, b){
                return a-b;
            }
            class multiMath(int a, b){
                return a*b;
            }
            class divMath(int a, b){
                return a/b;
            }

            string a, b, c = Console.ReadLine();
            if(c == "+"){
                Console.WriteLine(plusMath(a,b));
            }
            else if(c == "-"){
                Console.WriteLine(minusMath(a,b));
            }
            else if(c == "*"){
                Console.WriteLine(multiMath(a,b));
            }
            else if(c == "/"){
                Console.WriteLine(divMath(a,b));
            }
            else{
                return;
            }
            







        }
    }
}
```