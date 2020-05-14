#include <cstring>  
#include <vector>   
#include <iostream> 
using namespace std;
class Matrix;


class Matrix { 
 int** values ; 
 int row, column ; 
public:
 //default setting
 Matrix(){values = 0; row = 0; column = 0;};
 
 //constructor
 Matrix(int a, int b){
  row = a ;
  column = b ;
 }
 
 ~Matrix(){};
 
 //set value
 void setValues(int a , int b, int c, int d){ //buffer overrun solve
  values =  new int*[row];
  for(int i = 0; i < row; ++i)
      values[i] = new int[column];
  values[0][0] = a; 
  values[0][1] = b;
  values[1][0] = c;
  values[1][1] = d;
  
 }
 
 int** getval(){
  return values ;
 }
 
 int getrow(){
  return row;
 }
 
 int getcol(){
  return column;
 }
 
 //operator overloading +
 Matrix operator+(Matrix &ref){
  Matrix NUMBOX(row, column);
  NUMBOX.setValues(values[0][0]+ref.getval()[0][0],values[0][1]+ref.getval()[0][1],values[1][0]+ref.getval()[1][0],values[1][1]+ref.getval()[1][1]);
  return NUMBOX;
 }
//operator overloading *
 Matrix operator*(int a){
  Matrix NUMBOX(row, column);
  NUMBOX.setValues(a*values[0][0],a*values[0][1],a*values[1][0],a*values[1][1]);
  return NUMBOX;
 }

} ;


istream& operator>> ( istream& is, Matrix& str ) {
    int a,b,c,d;
    cout << "enter array"<<endl;
    is >> a>>b>>c>>d;
    str.setValues(a,b,c,d);
    
    return is;
}

ostream& operator<< ( ostream& os,  Matrix& str ) {
	os<< endl;
    for(int i  =0; i< str.getrow(); i++){
   		for(int j = 0; j< str.getcol();j++){
    		os << str.getval()[i][j] << ' ';
   		}
   		os << endl;
   }
    return os;
}

int main() { 
 Matrix m1(2, 2), m2(2, 2) ;
 cin >> m1 ; 
 cout << m1;
 cin >> m2 ;
 cout << "\naddition";
 Matrix m3(m1 + m2); 
 cout << m3 ;
 Matrix m4(2, 2);
 cout << "\nmultiplation";
 m4 = m3 * 10 ;
 cout << m4 ;
 
}
 
