/* Malveillant Message Quest
   Kairehn (12/28/2007) */
#include <lib.h>
inherit LIB_MISSION;
#include "/domains/peninsula/areas/sulumus/wanted.h"
#include <domains.h>

static void create() {
  ::create();
  SetMissionName("A Blood-red Garnet");
  SetTown("Malveillant");
  SetMissionDescription(
    "I'm glad to see you back, I was starting to think you'd frozen to "
    "death on the road. Good. Now that we know the road is passable, we "
    "can begin to make further plans. Now, I have another assignment for "
    "you. Our gem store isn't seeing very much business these days, a "
    "problem we directly associate with the jeweler operating in the Sulumus "
    "trading post, just off the Haven Road. She goes by the name of Raspina, "
    "and has been known to undercut our prices. Deliver a rose to her, as you "
    "did to Brook in Haven. She'll get the message. If not, well, it means "
    "more work for you, and that isn't such a bad thing."    
    );  
  SetMissionLevel(30, 500);
  SetMissionPriority(56);
  SetReward("15000 XP");
}

int CheckCompletedMission(object who) {  
  object *roses = ({ });
  object *raspina = ({ });  
  int listsize, x = 0; 
  string target = "/domains/peninsula/areas/sulumus/wanted.h";
  string str = "";
  string dude = lower_case(who->GetName());
  string *newWanted = ({ dude });
  
  if (base_name(environment(who)) == PENINSULA_AREAS "sulumus/room/civ_tent1") {       
    roses = filter(all_inventory(who), (: $1->GetShort() == "a black rose" :) );
    if (sizeof(roses) < 1) return 0;
    raspina = filter(all_inventory(environment(who)), (: living($1) && $1->GetName() == "Raspina" :));
    if (sizeof(raspina) < 1) return 0;
    roses[0]->eventDestruct();
    who->eventPrint("You have delivered a black rose to Raspina.");
    raspina[0]->eventForce("speak Hah. You dare threaten me? You're no longer "
      "welcome here. Our guards will take care of you!");
    raspina[0]->eventForce("shout Guards!");
    who->AddExperience(15000);
    
    // This is about to get interesting. Don't panic!
  
    str += "/* Sulumus Wanted Poster.\n   Kairehn (12/28/2007)\n\n   " + 
      "This file is being read and rebuilt by a mission now.\n   " + 
      "Feel free to add or remove entries, just stick with the existing " + 
      "formatting!*/\n";    
  
    str += "\nstring *Wanted = ({\n";  
    listsize = sizeof(Wanted);
    for (x = 0; x < listsize; x++)
    {
      str += "\"" + Wanted[x] + "\",\n";
    }
    str += "\"" + lower_case(who->GetName()) + "\",\n});\n\n";
    str += "mapping Crimes = ([\n";
    for (x = 0; x < listsize; x++)
    {
      str +=  "\"" + Wanted[x] + "\" : " + "\"" + Crimes[Wanted[x]] + "\",\n";
    }  
    str += "\"" + lower_case(who->GetName()) + "\" : \"threatening a merchant\",\n]);";      
    Wanted += newWanted;
    Crimes[Wanted[listsize]] = "threatening a merchant";            
    unguarded((: write_file, target, str, 1 :));    
    return 1;
  }
  return 0;        
}

int CanGetMission(object who) {
  if (who->GetNationality() != "Malveillant") return 0;  
  return 1;
}
