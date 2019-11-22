/*************************************************************************************************************************************
This problem was asked by Microsoft.
Implement a URL shortener with the following methods:
shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.
Hint: What if we enter the same URL twice?
**************************************************************************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

string idToShortUrl(long int n){
	string encode = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string shortUrl;
	while(n){
		shortUrl += encode[n%62];
		n/=62;
	}
	reverse(shortUrl.begin(),shortUrl.end());
	return shortUrl;
}

long int shortUrltoId(string shortUrl){
	long int id =0;
	for(int i=0;i<shortUrl.length();i++){
		if ('a' <= shortUrl[i] && shortUrl[i] <= 'z') 
          id = id*62 + shortUrl[i] - 'a'; 
        if ('A' <= shortUrl[i] && shortUrl[i] <= 'Z') 
          id = id*62 + shortUrl[i] - 'A' + 26; 
        if ('0' <= shortUrl[i] && shortUrl[i] <= '9') 
          id = id*62 + shortUrl[i] - '0' + 52;
	}
	return id;
}


int main() {
	string url = "";
	//Store the url in the DB and get the uniqued id from DB now convert that id to the shortstring
	string prefix = "www.sho.rt/";
	string shortUrl = idToShortUrl(33546546);
	cout<<prefix+shortUrl+"/"<<endl;
	//in order to get the actual url conver the make an API which convert the string part after the prefix in short url
	//to the unique id and use id to query actual url form DB
	cout<<shortUrltoId(shortUrl)<<endl;
	return 0;
}
