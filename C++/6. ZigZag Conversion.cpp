#include <iostream>
#include <vector>
#include <string>

class Solution{
  public:
    int rows = 0;
    std::string string = "";
    std::vector<std::string> list;
    Solution(int a_rows, std::string a_string){
      string = a_string;
      rows = a_rows;
      Convert();
      show();
    }
    void Convert(){
      int l_index = string.length() - 1;
      int offset = 2*rows - 2;
      for (int i= 0; i < rows; i++){
        list.push_back("");
      }
      for(int x = 0; x < (l_index + 1); x += offset){
        for(int j=0; j < list.size(); j++){
          if(x + j <= l_index && j != rows -1){
            list[j] += string[x + j];
            for(int d = 1; d < offset-2*j; d++){
              list[j] += " ";
            }
          }
          if(x + offset - j <= l_index){
            if(j != 0){
              list[j] += string[x + (offset-j)];
              for(int d= 1; d< 2*j; d++){
                list[j] += " ";
              }
            }
          }
        }
      }
      for(int i = 0; i < rows; i++){
        for( int j = 0; j < i; j++){
          list[i] += " ";
        }
      }

    }
    void show(){
      for(int i = 0; i < list.size(); i++){
        std::cout << (list[i]) << std::endl;
      }
    }

};
//testing code 
int main(){
  Solution sol =  Solution(4, "iliketodopullrequests");
}
