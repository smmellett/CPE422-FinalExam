#include <iostream>         // for the input/output
#include <stdlib.h>         // for the getenv call
#include <sys/sysinfo.h>    // for the system uptime call
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include"GPIO.h"
#define Button_GPIO "/sys/class/gpio/gpio28/"
using namespace std;
using namespace cgicc;


int main(){
   Cgicc form;                      // the CGI form object
   string cmd;                      // the Set LED command
   GPIO inGPIO(28);
   inGPIO.setDirection(INPUT);
   state = inGPIO.getValue();
   // get the state of the form that was submitted - script calls itself
//   bool isStatus = form.queryCheckbox("status");
//   form_iterator it = form.getElement("cmd");  // the radio command
//  if (it == form.getElements().end() || it->getValue()==""){
//      cmd = "off";                     // if it is invalid use "off"
//   }
//   else { cmd = it->getValue(); }      // otherwise use submitted value
//   char *value = getenv("REMOTE_ADDR");    // The remote IP address

   // generate the form but use states that are set in the submitted form
   cout << HTTPHTMLHeader() << endl;       // Generate the HTML form
   cout << html() << head() << title("Mellett Final Exam") << head() << endl;
   cout << body() << h1("CPE 422 Final Exam: Reading Digital Input") << endl;
   cout << body() << h1("Reading a GPIO Pin via a Web Browser") << endl;
   cout << "<form action=\"/cgi-bin/read_digital.cgi\" method=\"POST\">\n";
   cout << "<div> <input type=\"submit\" value=\"Read Switch\"";
   cout << "Switch State:" << state << "</div>";
   cout << "</div></form>";

   cout << body() << html();

