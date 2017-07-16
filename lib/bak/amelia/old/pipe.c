#include <lib.h>
#include <climb.h>
#include <daemons.h>
#include <meal_types.h>

inherit LIB_CLIMB;
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

void DoSpam();
string GetNewSpam();
string theword = "SPAM";
int countdown(string time);
int setlines(string numlines);
int timer, detonating, lines;

static void create() {
  meal::create();
  smell::create();
  AddSave( ({ "theword", "timer", "detonating", "lines" }) );
  SetKeyName("Gaby's nifty toy");
  SetId( ({ "toy"}) );
  SetShort("%^RED%^BOLD%^Gaby's peace pipe%^RESET%^");
  SetLong("This is Gaby's peace pipe.  Be very careful with it "
    "as it can get you into trouble and killed.");
  SetRead("default","This is Gaby's peace pipe.  The commands are:\n"
      "     suffer          smoke\n"
      "     prison          dappear\n"
      "     corpser         appear\n"
      "     talkto          destroy\n"
      "     countdown       smack\n"
      "     setlines        spawn\n"
      "     setword         types\n"
      "     find            invasion\n");
  SetValue(0);
  SetMass(0);
  SetMealType(MEAL_FOOD);
  SetStrength(1);
  SetMealMessages("You puff on the peace pipe.",
    "$N takes a puff from a peace pipe.");
  SetSmell("The peace pipe smells like cedar.");
  SetTouch("It smooth and silky.");
  SetClimb("/realms/gabriel/workroom", CLIMB_UP);
  SetClimb("/domains/heaven/room/olympus", CLIMB_INTO);
  SetPreventGet("Dont touch Gaby's peace pipe dammit!");
  set_heart_beat(1);
}

void init() {
  ::init();
  add_action("suffer","suffer");
  add_action("prison","prison");
  add_action("corpser","corpser");
  add_action("smack","smack");
  add_action("talkto", "talkto");
  add_action("countdown", "countdown");
  add_action("setlines", "setlines");
  add_action("setword", "setword");
  add_action("smoke","smoke");
  add_action("dappear","dappear");
  add_action("appear","appear");
  add_action("spawn","spawn");
  add_action("find","find");
  add_action("invasion","invasion");
  add_action("types","types");
  add_action("destroy","destroy");
  this_player()->AddChannel("intercre");
  this_player()->AddChannel("intergossip");
  this_player()->AddChannel("apostles");
}

int suffer(string str) 
{
  object who = find_living(str);
  object suffer = new("/realms/gabriel/obj/toys/suffer");

  if (who->GetKeyName() == "gabriel")
  {
    who->eventPrint("He gives you a toy and you try to use it "
      "on him, for shame.");
    eventDestruct();
    return 1;
  }
  else if (!who || !suffer) 
  {
    message("system", "Error targeting or loading suffering.",
      this_player() );
    return 1;
  }
  else
  {
    who->eventPrint("%^YELLOW%^Someone just gave you a "
      "handful of suffering.%^RESET%^");
    suffer->eventMove(who);
    return 1;
  }
}

int prison(string str) 
{
  object who = find_living(str);
  object prison = new("/realms/gabriel/obj/toys/prison");

  if (who->GetKeyName() == "gabriel")
  {
    who->eventPrint("He gives you a toy and you try to use it "
      "on him, for shame.");
    eventDestruct();
    return 1;
  }
  else if (!who || !prison) 
  {
    message("system", "Error targeting or loading prison.",
      this_player() );
    return 1;
  }
  else
  {
    prison->eventMove(who);
    return 1;
  }
}

int corpser(string target) 
{
  object who = find_living(target);
  object corpse = new(LIB_CORPSE);

  if (who->GetKeyName() == "gabriel")
  {
    who->eventPrint("He gives you a toy and you try to use it "
      "on him, for shame.");
    eventDestruct();
    return 1;
  }
  else
  {
    who->eventPrint("%^RED%^Oops.  You die.%^RESET%^");
    corpse->SetCorpse(who);
    corpse->SetStrength(2000000);
    corpse->SetRace("sheep");
    corpse->eventMove(environment(who));
    message("blah",who->GetCapName() + " dies horribly.",environment(who),
      ({ who,this_player() }));
    if(this_player() == who) 
    {
      return 1;
    }
    this_player()->eventPrint("Haha.  They died.");
    return 1;
  }
}

int smack(string target) 
{
  object who = find_living(target);

    if ((who->GetKeyName() == "gabriel") || (in_edit(who)) || (playerp(who)))
  {
    who->eventPrint("You cant smack that person.");
    eventDestruct();
    return 1;
  }
  who->eventPrint("%^BLUE%^Some asshole just smacked you into "
    "linkdeath!%^RESET%^");
  who->eventDestruct();
  return 1;
}

int find(string str) 
{
  object ob;
  if (ob = find_living(lower_case(str))) 
  {
    ob = environment(ob);
  }
  if (!ob) (ob = find_object(str));
  if(ob) 
  {
    this_player()->eventMoveLiving(ob, "");
    return 1;
  }
  this_player()->eventPrint("Failed to find specified object in goto.");
  return 1;
}

int spawn(string arg) 
{
  object newitem;
  if(!arg) return 0;
  newitem = new(arg);
  newitem->eventMove(find_living(this_player()));
  return 1;
}   

int appear() 
{
  this_player()->SetInvis(0);
  return 1;
}

int dappear() 
{
  this_player()->SetInvis(1);
  return 1;
}

int destroy(object args) 
{
  object ob = to_object(args);
  ob->eventDestruct(environment());
  return 1;
}

int talkto(string args) 
{
  string person, line;
  object ob;
  if (!args) return 0;
  sscanf(args, "%s %s", person, line);
  if (!person || !line) 
  {
    this_player()->eventPrint("You aren't supplying enough arguments.");
    return 1;
  }
  if (!(ob = find_living(person))) 
  {
    this_player()->eventPrint("No such person.");
    return 1;
  }
  this_player()->AddChannel(line);
  ob->AddChannel(line);
  this_player()->eventPrint(line + " added to " + capitalize(person) + ".");
  ob->eventPrint(capitalize(this_player()->GetName()) + " has created a "
                 "private channel named " + line + ".");
  return 1;
}

static void heart_beat() 
{
  timer--;
  if ((timer < 1) && detonating) DoSpam();
}

int setword(string newword) 
{
  if (!newword) return 0;
  theword = strip_colours(newword);
  message("bomb", "\"" + theword + "\" will be sent.", this_player());
  return 1;
}

int setlines(string numlines) 
{
  if (!numlines) return 1;
  lines = to_int(numlines);
  if (lines > 10) (lines = 10);
  message("bomb", "Lines set to " + lines, this_player());
  return 1;
}

int countdown(string time) 
{
  if (this_player()->GetKeyName() != "gabriel") return 0;
  if (detonating) 
  {
    message("bomb", "The spambomb is already counting down!", this_player());
    return 1;
  }
  if (!time) 
  {
    message("bomb", "You need to choose a time.", this_player());
    return 1;
  }
  detonating = 1;
  timer = to_int(time);
  message("bomb", "Counting down from " + timer, this_player());
  return 1;
}

void DoSpam() 
{
  int i;
  if (!lines) lines = 10;
  for(i = lines; i > 0; i--) 
  {
    message("bomb", "%^" + GetNewSpam() + GetNewSpam() + GetNewSpam() + GetNewSpam() +

      GetNewSpam() + GetNewSpam() + GetNewSpam() + GetNewSpam() + GetNewSpam() +
      GetNewSpam() + GetNewSpam() + GetNewSpam() + GetNewSpam() + GetNewSpam() + 
      GetNewSpam(), environment());
  }
  if (find_living("gabriel")) {
    message("bomb", lines + " lines of \"" + theword + "\" sent to " + 
      environment()->GetShort() + ".", find_living("gabriel"));
  }
  eventDestruct();
}

string GetNewSpam() {
  string spamword;
  string *colorset = ({ "BLACK%^", "BLUE%^", "MAGENTA%^", "YELLOW%^",
    "RED%^", "CYAN%^", "ORANGE%^", "GREEN%^", "WHITE%^", "" });
  string *boldset = ({ "B_BLACK%^", "B_BLUE%^", "B_MAGENTA%^", 
    "B_YELLOW%^", "B_RED%^", "B_CYAN%^", "B_ORANGE%^", "B_GREEN%^",
    "B_WHITE%^", "" });
  spamword = colorset[random(sizeof(colorset))];  
  spamword += boldset[random(sizeof(boldset))];
  if (random(2)) spamword += "FLASH%^";
  spamword += theword + "%^RESET%^";
  return spamword;
}

int smoke(string args) 
{
  if(args != "pipe") 
  {
    return 0;
  }
  message("my_action","You puff deeply on the godtoy.\n"
    "A %^RED%^light%^RESET%^ flares at the tip of the thread.\n"
    "You exhale and begin to see the %^BLUE%^c%^WHITE%^o%^MAGENTA%^l"
      "%^YELLOW%^o%^BLACK%^r%^CYAN%^s%^RESET%^.",
    this_player());
  message("other_action",this_player()->GetName() + " puffs deeply "
    "on a thread.\n"
    "A light flares up at the tip of the thread.\n"
    + capitalize(nominative(this_player())) + " begins changing "
      "%^BLUE%^c%^WHITE%^o%^MAGENTA%^l%^YELLOW%^o%^BLACK%^r%^CYAN%^s%^RESET%^.",
    environment(this_player()),
    this_player());
  return 1;
}

int invasion( string arg ) 
{
  object inv;

  if (!archp(this_player())) 
  {
    this_player()->eventPrint("BAD BAD BAD BAD!!! The invader goes poof!");
    this_object()->eventDestruct();
    return 1;
  }

  switch(arg) 
  {
    case "1" :   /* firegiant invasion of argoth */
      inv = new("/std/invasions/firegiant/firegiant_inv");
      break;
    case "2" :   /* bandit invasion of haven */
      inv = new("/std/invasions/bandit/bandit_inv");
      break;
    case "3" :   /* demon invasion of haven */
      inv = new("/std/invasions/demon/demon_inv");
      break;
    case "4" :   /* pirate invasion of haven */
      inv = new("/domains/southern_coast/invasions/pirate/pir_inv");
      break;
    case "5" :   /* 1st wave of undead invasion of haven */
      inv = new("/std/invasions/undead/undead_inv");
      break;
    case "6" :   /* 2nd wave of undead invasion of haven */
      inv = new("/std/invasions/undead/undead_2_inv");
      break;
    case "7" :   /* kylin templar invasion of jidoor */
      inv = new("/std/invasions/jidoor/templar_inv");
      break;
    case "8" :   /* lizardman invasion of jidoor */
      inv = new("/domains/valley/invasions/lizardmen/lmij_inv");
      break;
    case "9" :   /* orc invasion of jidoor */
      inv = new("/domains/valley/invasions/orcs/orc_inv");
      break;
    case "10" :  /* bandit invasion of parva */
      inv= new("/std/invasions/parva_bandit/bandit_inv");
      break;
    case "11" :  /*  kylin templar of parva */
      inv = new("/std/invasions/parva/templar_inv");
      break;
    case "12" :  /* pirate invasion of parva */
      inv = new("/domains/havenwood/invasions/pirate/parva_pir_inv");
      break;
    case "13" :  /* ogre invasion of soleil */
      inv = new("/domains/westwood/invasions/ogre_soleil/ogre_inv");
      break;

  }
  INVASION_D->eventRegisterInvasion(inv, this_player());
  return 1;
}

int types(string useless) 
{
  message("invader",
     "%^RED%^Type invasion # to initiate invasion.%^RESET%^\n"
     "%^BOLD%^GREEN%^ 1  Firegiants %^RESET%^-------------> %^BOLD%^GREEN%^Argoth%^RESET%^ \n"
     "%^BOLD%^GREEN%^ 2  Bandits %^RESET%^----------------> %^BOLD%^GREEN%^Haven%^RESET%^ \n"
     "%^BOLD%^GREEN%^ 3  Demons %^RESET%^-----------------> %^BOLD%^GREEN%^Haven%^RESET%^ \n"
     "%^BOLD%^GREEN%^ 4  Pirates %^RESET%^----------------> %^BOLD%^GREEN%^Haven%^RESET%^ \n"
     "%^BOLD%^GREEN%^ 5  1st Wave of Undead %^RESET%^-----> %^BOLD%^GREEN%^Haven%^RESET%^ \n"
     "%^BOLD%^GREEN%^ 6  2nd Wave of Undead %^RESET%^-----> %^BOLD%^GREEN%^Haven%^RESET%^ \n"
     "%^BOLD%^GREEN%^ 7  Kylin Templars %^RESET%^---------> %^BOLD%^GREEN%^Jidoor%^RESET%^ \n"
     "%^BOLD%^GREEN%^ 8  Lizardmen %^RESET%^--------------> %^BOLD%^GREEN%^Jidoor%^RESET%^ \n"
     "%^BOLD%^GREEN%^ 9  Orcs %^RESET%^-------------------> %^BOLD%^GREEN%^Jidoor%^RESET%^ \n"
     "%^BOLD%^GREEN%^10  Bandits %^RESET%^----------------> %^BOLD%^GREEN%^Parva%^RESET%^ \n"
     "%^BOLD%^GREEN%^11  Kylin Templars %^RESET%^---------> %^BOLD%^GREEN%^Parva%^RESET%^ \n"
     "%^BOLD%^GREEN%^12  Pirates %^RESET%^----------------> %^BOLD%^GREEN%^Parva%^RESET%^ \n"
     "%^BOLD%^GREEN%^13  Ogres %^RESET%^------------------> %^BOLD%^GREEN%^Soleil%^RESET%^ \n",
      this_player());
  return 1;
}
