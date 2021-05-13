// https://practice.geeksforgeeks.org/problems/reverse-a-string/1

string reverseWord(string str){
    
  //Your code here
  string res;
  res = "";
  for(int i = str.length()-1;i>=0;i--)
  {
      res = res + str[i];
  }
  return res;
  
}
