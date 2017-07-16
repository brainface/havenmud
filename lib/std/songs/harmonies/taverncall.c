#include <lib.h>
#include <music.h>
#include <daemons.h>
inherit LIB_SONG;

private mapping TavernPlaces = ([
   "Averath"      : "/domains/averath/towns/averath/room/tavern",
   "Dalnairn"     : "/domains/averath/towns/dalnairn/room/tavern",
   "Glimmerdin"   : "/domains/crystal_reaches/towns/glimmerdin/room/tavern",
   "Soleil"       : "/domains/westwood/towns/soleil/room/inn",
   "Westwoods"    : "/domains/westwood/areas/monastery/room/tavern",
   "Haven"        : "/domains/southern_coast/towns/haven/room/ruperts/inn",
   "Sanctum"      : "/domains/peninsula/towns/sanctum/room/inn",
   "Keryth"       : "/domains/frostmarches/towns/keryth/room/tavern",
   "Yozrath"      : "/domains/yozrath/towns/yozrath/room/inn",
  //"Durgoroth"   : "/domains/frostmarches/towns/durgoroth/room/inn",
   "Grymxoria"    : "/domains/estergrym/towns/grymxoria/room/tavern",
   "Malveillant"  : "/domains/havenwood/towns/malveillant/rooms/inn",
   "Jidoor"       : "/domains/valley/towns/jidoor/room/misc_buildings/inn",
   "Baria"        : "/domains/baria/towns/baria/room/commonhut",
   "Lloryk"       : "/domains/crystal_reaches/towns/lloryk/room/tavern",
   "Frostmarches" : "/domains/frostmarches/areas/inn/room/main",
   "Parva"        : "/domains/havenwood/towns/parva/room/tavern",
   "Xandria"      : "/domains/xandria/towns/lisht/room/gnoll/inn",
   "Gurov"        : "/domains/gurov/towns/gurov/room/tavern",
   "Tairi"        : "/domains/tairi/towns/tairi/room/inn",
  ]);

void ProcessTarget(string town, object who);
void CheckTown(string town, object who);

static void create() {
  song::create();
  SetSong("tavern call");
  SetRules("");
  SetSongType(SONG_OTHER);
  SetMagicCost(200, 600);
  SetDifficulty(40);
  SetSkills( ([
    "vocal music" : 400,
    "instrumental music"   : 400,
    ]) );
  SetHelp(
   "This song allows the bard to sing a wonderful harmony about many different "
   "places around the world. The harmony invokes such great power that it draws "
   "the singer as well as his companions to the place the bard sings about."
    "An invalid choice will result in the caster being drained of all their magic.");
}

varargs int CanSing(object caster, int level, string u, object array targets) {
  object target = targets[0];
  object env = environment(caster);
 
  if (env->GetProperty("no teleport")) {
    caster->eventPrint("You cannot seem to flee this place.");
    return 0;
  }
  SetDifficulty(40);
  return ::CanSing(caster, level, u, targets);
}

varargs int eventSing(object caster, int level, string u, object array targets) {
  
  send_messages( ({ "sing" }),
    "$agent_name $agent_verb loudly, the melody hangs in the air for a moment...",
    caster, 0, environment(caster) );
  caster->eventPrint("%^BOLD%^RED%^Where would you like to sing? "
  "(Options: " + conjunction(keys(TavernPlaces)) + ")" );
  input_to( (: CheckTown :), caster );
  return 1;
}

void CheckTown(string town, object who) {
   object env  = environment(who);
   object envT; 
   int distance;
   string tmp;
  
   tmp = capitalize(town); 
   envT = (object)TavernPlaces[tmp];
   
  if (member_array(tmp, keys(TavernPlaces) ) == -1) {
    who->eventPrint("That (" + town + ") does not seem to be a valid choice!");
     who->AddMagicPoints(-who->GetMagicPoints());
    send_messages( ({ "sing" }),
    "$agent_possessive_noun voice cracks causing the melody to unravel.",
    who, 0, environment(who) );
    return;   
  }
    distance = DISTANCE_D->GetDistance(env->GetDomain(), envT->GetDomain());
    SetDifficulty(75 * (1 + distance));
    return ProcessTarget(tmp, who);
}

void ProcessTarget(string tmp, object who) {
    int *failure = ({ 0, 0 });
    int fc = 0;
    object* followers;
    followers = who->GetFollowers();
    if(!followers) followers = ({});
    if (who->GetTestChar()) debug("Failure : " + failure[0] + ", " + failure[1]);
    failure[0] = random(GetDifficulty());
    failure[0] = (failure[0] * 50) / (who->GetSongLevel(GetSong()));
    failure[0] += failure[0] * who->GetRecoveryTime(); 
    foreach(string skill in GetSkills()) {
            failure[0] -= (who->GetSkillLevel(skill) - GetRequiredSkill(skill)) * 5; 
      }
    if (failure[0] < 0) failure[0] = 0;
    failure[1] = random(100);
    if (who->GetTestChar()) debug("Failure : " + failure[0] + ", " + failure[1]);
    if (failure[1]  < failure[0]) {
            fc = failure[0] - failure[1];
            if (fc > GetSongLevel() * 4) fc = GetSongLevel() * 4;
            eventFail(who, fc);
            eventTrainSong(who, 0);
            return;
      }
  eventTrainSong(who, 1);
  who->eventMoveLiving(TavernPlaces[tmp], "$N fades into the melody.", "$N appears out from an echo!");
  followers->eventMoveLiving(TavernPlaces[tmp], "$N fades into the melody.", "$N appears out from an echo!");
  who->eventPrint("You begin to sing about " + tmp + " and your harmony carries you there.");
  return;
}

