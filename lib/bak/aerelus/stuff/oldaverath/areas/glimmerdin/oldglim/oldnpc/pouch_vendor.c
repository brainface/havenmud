 /*
  * Pouch vendor
  * Balishae 1997
  */
#include <lib.h>
#include "../glim.h"
#include "/realms/balishae/path.h"

#define TOB this_object()
#define LANGUAGES this_object()->GetLanguages()

inherit LIB_SENTIENT;

void DoSpeak(object who, string theText);
static void DoHawk();
static void DoVend(object who, string theVerb, string arg);

int flag;


static void create()
{
  sentient::create();
  SetKeyName("merchant");
  SetId( ({"vendor","merchant","dwarf", "town_wander"}) );
  SetAdjectives( ({"pouch","handbag","fine","dwarf"}) );
  SetShort("a pouch vendor");
  SetLong("Almost delicate looking, for a dwarf that is, the merchant is "
          "selling fine handbags");
  SetLevel(20);
  SetWander(6);
  SetRace("dwarf");
  SetClass("merchant");
  SetGender("male");
  AddInventory(G_ROOM + "case","wield case");
  AddInventory(G_OBJ + "l_tunic","wear tunic");
  
  SetLanguage("Eltherian",100);  //Set Languages so that vendor can speak
  SetLanguage("Enlan",100);      //to any who wish to deal with him.
  SetLanguage("Uruk",100);
  SetLanguage("Valsor",100);
  SetLanguage("Oiseau",100);
  SetLanguage("Gobyshkin",100);
  
  SetCommandResponses( (["sell" : (:DoVend:)]) );
}


void init()
{
  sentient::init();
  if (!userp(this_player())) return;
  if(flag) return;
  flag = call_out("DoHawk",random(30)+10);
}


void DoSpeak(object who, string theText)
{
  string theLang = who->GetNativeLanguage();
  
  eventForce("speak in " + theLang + " " + theText);
}


static void DoHawk()
{
  string Language,m_mesg,m_volume;
  
  Language = LANGUAGES[random(sizeof(LANGUAGES))];
  
  switch(random(5))
  {
  	case 0 :
 	  m_mesg = "Fine handbags, for gentlemen or ladies.";
 	  break;
 	case 1 :
 	  m_mesg = "Fine handbags, only 5 nuggets.";
 	  break;
  	case 2 :
 	  m_mesg = "Crafted of the finest skins.";
 	  break;
 	case 3 :
 	  m_mesg = "Get your fine pouches here.";
 	  break;
 	case 4 :
 	  m_mesg = "Something to keep your baubels and cash in!";
 	  break;
  }
  if(random(4)) m_volume = "speak ";
  else m_volume = "shout ";
  
  eventForce(m_volume + "in " + lower_case(Language) + " " + m_mesg);
  flag = call_out("DoHawk",random(30)+10);
}


static void DoVend(object who, string theVerb, string arg)
{
  object thePlayer = who;
  object ob;
  int i;
  
  if(thePlayer->GetCurrency("nuggets") < 5)
  {
    DoSpeak(thePlayer,"Do I look like I'm doing this for charity?  No "
            "handouts, get yourself some nuggets and we'll do business.");
    return;
  }
  
  if( !arg ) return;
  switch(lower_case(arg))
  {
  	 case "pouch" :
   	case "fine pouch" :
    case "handbag" :
    case "fine handbag" :
    {
      for(i=1;i<3;i++)
      {
        ob = new(G_OBJ + "handbag.c");
        ob->eventMove(thePlayer);
      }
      message("environment",
        "The pouch vendor reaches into a case he carries and withdraws a "
        "fine looking pouch.",
        environment(this_object()));
        
      DoSpeak(thePlayer,"You won't find better quality than this.  I wish "
              "ye well.");
      thePlayer->AddCurrency("nuggets",-5);
      AddCurrency("nuggets",5);
      break;
    }
    default :
  	{
  	  DoSpeak(thePlayer,"I'm afraid I don't sell that.");
  	  break;
  	}
  }
  return;
}
