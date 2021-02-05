#include<string>
using namespace std;

const string ones[] = {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
// Array containing places notation starting from hundred all the way upto mahashankh
const string places[]={"hundred","thousand","lakh","crore","arab","kharab","neel","padma","shankh","mahashankh"};


//function which converts given string of max length 2 to words, also has additional parameter of places to add to the converted number
string getWords ( string digits , string place)
{
    string str="";
    int num = stoi(digits);
    if( num <= 20)      //condition to handle no. less than 21 as they have unique value for each no
    {
        str+=ones[num];
    }
    else                // condition if the value is greater than 20 to generate the 2 words which makes up the tenth and units
    {
        int units,tens;
        tens = num/10+18;
        units = num%10;
        str += ones[tens];
        if(units !=0)
        str += " "+ones[units];
    }
    if(str == "")           // if the no. is 00 then excludes the places value
        place="";
   
    if(place != "")
    {
        place +=" ";
        str+=" ";
    }
    
    return str + place;
}

bool isStringNum(string &s,string &words)       //validator function to make sure the entered no. is only integer 
{   if(s[0] == '-')                         //handles negetive sign for negetive integer
    {    s=s.substr(1);
         words +="minus ";
         if(s.length()==0)
            return false;
    }
    
    for(int i=0;i<s.length();i++)
        if(!isdigit(s[i]))
            return false;
    return true;
}

string num2word(string number)
{   
    string words="";
    if(!isStringNum(number,words) || number.length() > 21)       
    {
       words="Invalid input";
       return words;
    }
    if(number == "0")
    {
            words = "zero"; 
    }
    while(number.length()>0)
    {   int cut=2;
        switch (number.length())
        {
        case 1: cut=1;                                    
        case 2: words += getWords(number,"");
                number = number.substr(cut);
                break;
        
        case 3: words += getWords(number.substr(0,1),places[0]);    //hundreds is the only one with diff break
                number = number.substr(1);
                break;

        case 4: cut=1;                                                        //since from thousand onwards its 1 thousand or 10 thousand
        case 5: words += getWords(number.substr(0,cut),places[1]);            // cut variable handles how to slice the array to get the first 1 or 2 digits to convert to word
                number = number.substr(cut);
                break;
        case 6: cut=1;
        case 7: words += getWords(number.substr(0,cut),places[2]);
                number = number.substr(cut);
                break;
        case 8: cut=1;
        case 9: words += getWords(number.substr(0,cut),places[3]);
                number = number.substr(cut);
                break;
        case 10: cut=1;
        case 11: words += getWords(number.substr(0,cut),places[4]);
                number = number.substr(cut);
                break;
        case 12: cut=1;
        case 13: words += getWords(number.substr(0,cut),places[5]);
                number = number.substr(cut);
                break;
        case 14: cut=1;
        case 15: words += getWords(number.substr(0,cut),places[6]);
                number = number.substr(cut);
                break;
        case 16: cut=1;
        case 17: words += getWords(number.substr(0,cut),places[7]);
                number = number.substr(cut);
                break;
        case 18: cut=1;
        case 19: words += getWords(number.substr(0,cut),places[8]);
                number = number.substr(cut);
                break;
        default: cut = number.length() - 19;
                words += getWords(number.substr(0,cut),places[9]);
                number = number.substr(cut);
                break;
        
        }
    }
    words = words.erase(words.find_last_not_of(" ")+1);
    return words;
}