/*
* Maksymilian Kochan
* lista 2: zad3
* dotnet run
*/


class Bignum
{
  string a;

  public Bignum(int n)
  {
    this.a = n.ToString();
  }

  private Bignum(string s)
  {
    this.a = s;
  }

  public void print()
  {
    Console.WriteLine($"{this.a}");
  }

  private static string abs_add(string tmp, string tmp2)
  {
    string wyn = "";
    int len1 = tmp.Length, len2 = tmp2.Length, przen = 0;

    if(len1 < len2){
      (tmp2, tmp) = (tmp, tmp2);
      (len1, len2) = (len2, len1);
    }

    for(int i = 1; i <= len2; i++){
      int cyfra = tmp[len1 - i] + tmp2[len2 - i] + przen;
      if(cyfra > 9){
        cyfra = cyfra - 10;
        wyn = cyfra + wyn;
        przen = 1;
      }
      else{
        wyn = cyfra + wyn;
        przen = 0;
      }
    }

    for(int i = len2 + 1; i <= len1; i++){
      int cyfra = tmp[len1 - i] + przen - '0';
      if(cyfra > 9){
        cyfra = cyfra - 10;
        wyn = cyfra + wyn;
        przen = 1;
      }
      else{
        wyn = cyfra + wyn;
        przen = 0;
      }
    }

    if(przen == 1)
      wyn = '1' + wyn;
      
    return wyn;
  }

  private static int compare(string s1, string s2)
  {
    int s1L = s1.Length, s2L = s2.Length;
    if(s1L > s2L)
      return 0;
    else if(s1L < s2L)
    {
      return 1;
    }

    for(int i = 0; i < s1L; i++){
      if(s1[i] < s2[i])
        return 1;
      else if(s1[i] > s2[i])
        return 0;
    }
    return 0;
  }

  private static string normalize(string s){
    int i = 0, len = s.Length - 1;
    string wyn = "";
    while(i < len){
      if(s[i] != '0')
        break;
      i++;
    }
    
    for(int j = i; j <= len; j++){
      wyn += s[j];
    }
    return wyn;
  }
 

  private static string abs_subsruct(string num1, string num2)
  {
    int przen = 0;
    string znak = "";
    if(Bignum.compare(num1, num2) == 1){
      (num2, num1) = (num1, num2);
      znak = "-";
    }
    
    int len1 = num1.Length, len2 = num2.Length;

    string wyn = "";

    for(int i = 1; i <= len2; i++){
      int cyfra = num1[len1 - i] - num2[len2 - i] - przen;
      if(cyfra < 0){
        cyfra = cyfra + 10;
        przen = 1;
      }
      else{  
        przen = 0;
      }
    
      wyn = cyfra + wyn;
    }

    for(int i = len2 + 1; i <= len1; i++){
      int cyfra = num1[len1 - i] - '0' - przen;
      if(cyfra < 0){
        cyfra = cyfra + 10;
        przen = 1;
      }
      else{
        przen = 0;
      }

      wyn = cyfra + wyn;
    }
    wyn = znak + Bignum.normalize(wyn);
    return wyn; 
  }

  public static string validate(string s){
    string wyn = "";
    int len = s.Length;
    if(len >= 3 && s[0] =='-' &&  s[1] == '-')
      wyn = s.Substring(2);
    else if(len == 2 && s[0] == '-' && s[1] == '0')
      wyn = "0";
    else
      wyn = s;
    return wyn;
  }

  public Bignum add(Bignum bnum2){
    int sign1 = (this.a[0] == '-') ? 1 : 0;
    int sign2 = (bnum2.a[0] == '-') ? 1 : 0;
    string num1 = this.a.Substring(sign1), num2 = bnum2.a.Substring(sign1), wyn = "";

    if(sign1 == 0 && sign2 == 0)
      wyn = Bignum.abs_add(num1, num2);

    if(sign1 == 0 && sign2 == 1)
      wyn = Bignum.abs_subsruct(num1, num2);

    if(sign1 == 1 && sign2 == 0)
      wyn = '-' + Bignum.abs_subsruct(num1, num2);

    if(sign1 == 1 && sign2 == 1)
      wyn = '-' + Bignum.abs_add(num1, num2);
    
    wyn = Bignum.validate(wyn);

    return (new Bignum(wyn));
  }

  public Bignum subsruct(Bignum bnum2){
    int sign1 = (this.a[0] == '-') ? 1 : 0;
    int sign2 = (bnum2.a[0] == '-') ? 1 : 0;
    string num1 = this.a.Substring(sign1), num2 = bnum2.a.Substring(sign1), wyn = "";

    if(sign1 == 0 && sign2 == 0)
      wyn = Bignum.abs_subsruct(num1, num2);

    if(sign1 == 0 && sign2 == 1)
      wyn = Bignum.abs_add(num1, num2);

    if(sign1 == 1 && sign2 == 0)
      wyn = '-' + Bignum.abs_add(num1, num2);

    if(sign1 == 1 && sign2 == 1)
      wyn = '-' + Bignum.abs_subsruct(num1, num2);

    wyn = Bignum.validate(wyn);

    return (new Bignum(wyn));
  }
}



class Start
{
  static void Main()
  {
    Bignum num1 = new Bignum(3);
    Bignum num2 = new Bignum(3);
    Bignum num3 = num1.subsruct(num2);
    num1.print();
    num2.print();
    num3.print();
  }
}