// LoginAppProject.cpp : Defines the entry point for the application.
//
/*

#include "LoginAppProject.h"
#include <cpr/cpr.h>
#include <iostream>

bool PerformLogin(const string& url, const string& username, const string& password)
{
    cout << "Attempting to connect..." << endl;

    cpr::Response r = cpr::Post(cpr::Url{ url },
        cpr::Payload{ {"uname", username}, {"pass", password} },
        cpr::Header{ {"Content-Type", "application/x-www-form-urlencoded"} });

    if (r.error) {
        cerr << "Connection error: " << r.error.message << endl;
        return false;
    }

    cout << "Connected." << endl;

    if (r.status_code != 200) {
        cerr << "Login failed: " << r.status_code << endl;
        return false;
    }

    // login is sucessfull only if 2 conditions are met:-
    // 1. recived 200 ok status code
    // 2. the following text is found in the response body
    if (r.text.find("On this page you can visualize or edit you user information") != string::npos) {
        cout << "Login successful and HTML content displayed above." << endl;
        cout << r.text << endl;
        return true;
    }
    else {
        cerr << "Login not successful: expected content not found." << endl;
        return false;
    }
}

int main()
{
    string url = "http://testphp.vulnweb.com/userinfo.php";
    string username = "test";
    string password = "test";

    if (PerformLogin(url, username, password)) {
        cout << "Login successful." << endl;
    }
    else {
        cerr << "Login failed." << endl;
    }

    return 0;
}
*/

#include "LoginAppProject.h"
#include <cpr/cpr.h>
#include <string>
#include <iostream>
#include <regex>


using namespace std;

bool PerformLogin(const string& url, const string& username, const string& password, string& response_body)
{
    cout << "Attempting to connect..." << endl;

    cpr::Response r = cpr::Post(cpr::Url{ url },
        cpr::Payload{ {"uname", username}, {"pass", password} },
        cpr::Header{ {"Content-Type", "application/x-www-form-urlencoded"} });

    if (r.error) {
        cerr << "Connection error: " << r.error.message << endl;
        return false;
    }

    cout << "Connected." << endl;

    if (r.status_code != 200) {
        cerr << "Login failed: " << r.status_code << endl;
        response_body = r.text;
        return false;
    }

    if (r.text.find("On this page you can visualize or edit you user information") != string::npos) {
        response_body = r.text;
        return true;
    }
    else {
        cerr << "Login not successful: expected content not found. provided credentials might be incorrect" << endl;
        response_body = r.text;
        return false;
    }
}

string ExtractField(const string& response_body, const string& field_name)
{
    regex re("<td valign=\"top\">" + field_name + ":</td><td><(?:input type=\"text\" value=\"|textarea wrap=\"soft\" name=\"uaddress\" rows=\"5\" style=\"width:200px\">)(.*?)\"?\\s*(?:name|style)");
    smatch match;
    if (regex_search(response_body, match, re) && match.size() > 1) {
        return match.str(1);
    }
    return "";
}

int main()
{
    cout << "This is a login simulation." << endl;

    string url = "http://testphp.vulnweb.com/userinfo.php";
    string username;
    string password;

    cout << "Enter the username: ";
    getline(cin, username);

    cout << "Enter the password: ";
    getline(cin, password);

    string response_body;
    if (PerformLogin(url, username, password, response_body)) {
        cout << "Login successful." << endl;

        string name = ExtractField(response_body, "Name");
        string cc_number = ExtractField(response_body, "Credit card number");
        string email = ExtractField(response_body, "E-Mail");
        string phone = ExtractField(response_body, "Phone number");
        string address = ExtractField(response_body, "Address");

        cout << "User Information:" << endl;
        cout << "+=========================+" << endl;
        cout << "Name: " << name << endl;
        cout << "Credit Card Number: " << cc_number << endl;
        cout << "E-Mail: " << email << endl;
        cout << "Phone Number: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "+=========================+" << endl;
    }
    else {
        cerr << "Login failed." << endl;
    }

    cout << "Do you want to see the HTML response? (for testing purposes) (y/n): ";
    string user_input;
    getline(cin, user_input);

    if (user_input == "y" || user_input == "Y") {
        cout << response_body << endl;
    }
    else {
        cout << "HTML response not displayed." << endl;
    }

    return 0;
}





