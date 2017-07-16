#include <lib.h>
#include <std.h>
inherit LIB_NPC;

void DoHire(string arg);
void DoFollow(string arg);
void DoHalt(string arg);
void CheckAttack(object who, string theVerb, string arg);
void EndService(object who, string theVerb, string arg);
void DoSpeak(object who,string theText);
int MercResponseJob();
int MercResponseMerc();
void DoHelp(string arg);

object DaBoss;


static void create()
{
  npc::create();
  SetKeyName("mundane mercenary");
  SetId( ({ "mercenary", "merc", "fighter", "dwarf" }) );
  SetAdjectives( ({ "cocky", "dwarf", "mercenary", "fighter" }) );
  SetShort("a cocky dwarf fighter");
  SetLong("The tough looking dwarf quietly appraises you as a prospective "
          "employer.");
  SetRace("dwarf");
  SetClass("fighter");
  SetGender("male");

  SetInventory( ([
    STD_HACK "hand-axe" : "wield axe in right hand",
    STD_BLUNT "war-hammer" : "wield hammer in left hand",
    STD_ARMOUR "shirt/scale_mail_small" : "wear scale mail",
    STD_ARMOUR "pants/studded_leather_pants_small" : "wear pants",
    STD_ARMOUR "boot/leather_boot_small" : "wear boots",
    STD_ARMOUR "helmet/helm_open_small" : "wear helm",
    STD_ARMOUR "cloak/r_cape_small" : "wear cape",
  ]) );
  SetLevel(17);
  SetLanguage("Eltherian",100);
  SetLanguage("Enlan",100);
  SetLanguage("Blaodric",100);
  SetLanguage("Sprith",100);
  SetLanguage("Uruk",100);
  SetLanguage("Valsor",100);
  SetLanguage("Oiseau",100);

 SetTalkResponses( ([
    ({"hire","job"}) : (:MercResponseJob:),
    "mercenary" : (:MercResponseMerc:) ]) );

  SetCommandResponses( (["work" : (:DoHire:)]) );
  SetWander(5);
}


int MercResponseJob()
{
  object thePlayer = this_player();
  
  DoSpeak(thePlayer,"I can be hired for a mere 3000 Imperials.  All "
                    "ye need do is ask me to work for ye.");
}


int MercResponseMerc()
{
  object thePlayer = this_player();
  
  DoSpeak(thePlayer,"Aye, I be a mercenary.");
}


void DoSpeak(object who, string theText)
{
  string theLang = who->GetNativeLanguage();
  
  eventForce("speak in " + theLang + " " + theText);
}


void DoHire(string arg)
{
  object thePlayer;
  
  thePlayer = this_player();
  
  if(DaBoss == thePlayer)
  {
    DoSpeak(thePlayer,"Why ya bloomin idiot!  I already work for ye!");
    return;
  }
  if(DaBoss)
  {
  DoSpeak(thePlayer,"ATTENTION!  It appears that I have been "
             "bought out.  ye didn't really expect 'loyalty' from a "
             "mercenary did ye?");
    RemoveFriend(DaBoss->GetKeyName());
  }
  
  
  if(thePlayer->GetCurrency("imperials") < 3000)
  {
    if(thePlayer->GetProperty("MercCheat"))
    {
      DoSpeak(thePlayer,"I told ye not to cheat me before!");
      eventForce("attack " + lower_case(thePlayer->GetName()));
      return;
    }
    DoSpeak(thePlayer,"I would advise ye not to try to cheat me again!");
    thePlayer->SetProperty("MercCheat",1);
    return;
  }
  thePlayer->AddCurrency("imperials",-3000);
  DoSpeak(thePlayer,"Ah, so ye have the coin.  I would be glad to be "
             "of service.  A few things:\n"
             "1) I will go where ye leads me, however upon occasion nature "
             "calls and I might slip away to tend my own business.  All ye "
             "need do is come back to where I left off and ask me to follow "
             "ye again.\n"
             "2) I will guard your back against any agressor.  If anyone "
             "attacks ye.  I will stomp them into the very ground!\n"
             "3) If ye order me to, and ye got the required cash (300 "
             "imperials), I will attack and slay any foe.  All ye need to do "
             "is ask me to attack it.\n"
             "4) I will repeat this list if you ask me to help.\n"
             "5) If at any time ye no longer need me services, just ask me "
             "to leave.");
  AddCommandResponse("follow", (:DoFollow:));
  AddCommandResponse("attack", (:CheckAttack:));
  AddCommandResponse("leave",(:EndService:));
  AddCommandResponse("help",(:DoHelp:));
  
  
  SetWanderSpeed(0);
  DaBoss = thePlayer;
  
  eventForce("follow " + lower_case(DaBoss->GetName()));
  DaBoss->eventForce("lead mercenary");
  AddFriend(DaBoss->GetKeyName());
}


void DoFollow(string arg)
{
  object thePlayer = this_player();
  if(thePlayer->GetName() != DaBoss->GetName())
  {
    DoSpeak(thePlayer,
            "Oy!  Who do ye think I am?  Ye think I do this fer "
               "free?  I owe my loyalty to my employer, " +
               DaBoss->GetName() + ".");
    return;
  }
  DoSpeak(thePlayer,
          "Oh...Ye want me to follow ye.  Why didn't ye say so?");
  eventForce("follow " + lower_case(DaBoss->GetName()));
  DaBoss->eventForce("lead mercenary");
  
}

void CheckAttack(object who, string theVerb, string arg)
{
  object target;
  object thePlayer = this_player();

  eventForce("follow merc");
  if(thePlayer->GetName() != DaBoss->GetName())
  {
    DoSpeak(thePlayer,
            "Oy!  Who do ye think I am?  Ye think I do this fer "
            "free?  I owe my loyalty to my employer, " +
            DaBoss->GetName() + ".");
    return;
  }
  if(DaBoss->GetCurrency("imperials") < 300)
  {
    DoSpeak(thePlayer,"Well ye know boss, I would be glad to help ye out, "
               "but ye lack the one hundred imperials.");
    return;
  }
  if(!target = present(arg))
  {
    DoSpeak(thePlayer,"Aye!  I'll get...ummm, who was it ye wished me to "
               "attack?");
    return;
  }
  DoSpeak(thePlayer,"Aye!  I'll do your bidding!");
  eventForce("attack " + lower_case(target->GetName()));
  DaBoss->AddCurrency("imperials",-300);
  
}

void DoHelp(string arg)
{
  object thePlayer = this_player();
  if(thePlayer->GetName() != DaBoss->GetName())
  {
    DoSpeak(thePlayer,"Oy!  Who do ye think I am?  Ye think I do this fer "
               "free?  I owe my loyalty to my employer, " +
               DaBoss->GetName() + ".");
    return;
  }
  DoSpeak(thePlayer,"Ah, so ye have the coin.  I would be glad to be of "
             "service.  A few things:\n"
             "1) I will go where ye leads me, however upon occasion nature "
             "calls and I might slip away to tend my own business.  All ye "
             "need do is come back to where I left off and ask me to follow "
             "ye again.\n"
             "2) I will guard your back against any agressor.  If anyone "
             "attacks ye.  I will stomp them into the very ground!\n"
             "3) If ye order me to, and ye got the required cash (300 "
             "imperials), I will attack and slay any foe.  All ye need to do "
             "is ask me to attack it.\n"
             "4) I will repeat this list if you ask me to help.\n"
             "5) If at any time ye no longer need me services, just ask me "
             "to leave.");
}
  

void EndService(object who, string theVerb, string arg)
{
  object thePlayer = this_player();
  if(thePlayer->GetName() != DaBoss->GetName())
  {
    DoSpeak(thePlayer,"Oy!  Who do ye think I am?  Ye think I do this fer "
               "free?  I owe my loyalty to my employer, " +
               DaBoss->GetName() + ".");
    return;
  }
  DoSpeak(thePlayer,"Aye!  If ye ever need me services again, just call.");
  eventForce("follow merc");
  SetWanderSpeed(5);
  DaBoss = 0;
  RemoveCommandResponse("follow");
  RemoveCommandResponse("attack");
  RemoveCommandResponse("leave");
  
}
