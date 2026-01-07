//(1) isalnum
if (isalnum(ch1)) {
        std::cout << ch1 << " is alphanumeric." << std::endl;
    } else {
        std::cout << ch1 << " is not alphanumeric." << std::endl;
    }
//2.)// C++ program to convert whole string to
// using transform() function and ::toupper in STL// similarly for tolower
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    cout<<s1<<endl;
//3.)
