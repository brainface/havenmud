// The 'song of nature' spell
// Zeratul@Haven
// 11/05/2001

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("song of nature");
  SetRules("");
  SetMagicCost(50,50);
  SetStaminaCost(25,25);
  SetDifficulty(45);
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
     "vocal music" : 25,
     "instrumental music" : 25,
  ]) );
  SetHelp(
     "By utilizing the knowledge that song soothes the beast, the singer is able "
     "gain control over nature to help him if the need should arise. "
  );
  }

int eventCast(object who, int level, mixed limb, object array targets) {
  object furry;

  foreach(object ob in filter(livings(), (: environment($1) :))) {
    if (ob->GetOwner() == who->GetKeyName()) {
    who->eventPrint("Your unable to control more than you already are.");
    return 1;
   }
  }

  switch(level) {
    case 0..10 :
      furry = new("/realms/zeratul/songs/obj/bird");
      break;
    case 11..20 :
      furry = new("/realms/zeratul/songs/obj/deer");
      break;
    case 21..30 :
      furry = new("/realms/zeratul/songs/obj/coyote");
      break;
    case 31..50 :
      furry = new("/realms/zeratul/songs/obj/bear");
      break;
    case 51..70 :
      furry = new("/realms/zeratul/songs/obj/bear");
      furry += new("/realms/zeratul/songs/obj/coyote");
      break;
    case 71..90 :
      furry = new("/realms/zeratul/songs/obj/bear");
      furry += new("/realms/zeratul/songs/obj/bear");
      break;
    case 91..100 :
      furry = new("/realms/zeratul/songs/obj/polar_bear");
      furry += new("/realms/zeratul/songs/obj/polar_bear");
      break;

}

  furry->eventMove(environment(who));
  furry->AddFriend(who->GetKeyName());
  furry->SetOwner(who->GetKeyName());
  foreach(object sucker in who->GetEnemies()) furry->AddEnemy(sucker);
  furry->eventForce("follow " + who->GetKeyName());
  who->eventForce("lead first " + furry->GetKeyName());

  who->AddStaminaPoints(-GetStaminaCost(who));
  who->AddMagicPoints(-GetMagicCost(who));

  send_messages("call", "With a soothing melody, $agent_name "
                "%^GREEN%^BOLD%^$agent_verb%^RESET%^ forth the aid of nature.",
                who, furry, environment(who));
  return 1;
}
