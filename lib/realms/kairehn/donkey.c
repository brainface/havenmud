// Donkey does test stuff!

#include <lib.h>
inherit LIB_NPC;
// #include "/realms/kairehn/test.h"
int PreTest();
int DoTest(string who);

static void create() {
  ::create();
  SetKeyName("donkey");
  SetRace("horse", "donkey");
  SetGender("male");
  SetShort("a test donkey!");
  SetId( ({ "donkey" }) );  
  SetLong("I love donkey, donkey don't lie. I love donkey, almost as much as pie.");
  SetClass("animal");  
  SetLevel(1);
}

int PreTest()
{
   eventForce("speak I'm testing something for Kairehn!");
   eventForce("wince");
   if (DoTest("Kairehn")) { 
     eventForce("speak It worked! No riddings!");
     return 1;
   }
   eventForce("speak Uhoh, something went wrong.");
   eventForce("ffear");
   return 0;     
}

int DoTest(string who)
{  
//   string str = "/* Sulumus Wanted Poster.\n   Kairehn (12/28/2007)\n\n   " + 
//    "This file is being read and rebuilt by a mission now.\n   " + 
//    "Feel free to add or remove entries, just stick with the existing " + 
//    "formatting!*/\n";
//  string target = "/realms/kairehn/test.h";
//  int listsize;
//  int x;
//  
//  str = str + "\nstring *Wanted = ({\n";  
//  listsize = sizeof(Wanted);
//  for (x = 0; x < listsize; x++)
//  {
    //str = str + "\"" + Wanted[x] + "\",\n";
  //}
  //str = str + "\"" + lower_case(who) + "\",\n});\n\n";
  //str = str + "mapping Crimes = ([\n";
  //for (x = 0; x < listsize; x++)
  //{
//    str = str + "\"" + Wanted[x] + "\" : " + "\"" + Crimes[Wanted[x]] + "\",\n";
//  }  
//  str = str + "\"" + lower_case(who) + "\" : \"threatening a merchant\",\n]);";  
//  if (write_file(target, str, 1)) 
//  {      
    //string *newWanted = ({ lower_case(who) });
    //Wanted += newWanted;
    //Crimes[Wanted[listsize]] = "threatening a merchant";
    //return 1;
  //}
  //return 0;
  return 1;
}