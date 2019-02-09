// crystal ball by whoknows whenknows

// mahkefel 2019: I'm lazy and just added behavior to someone's
// existing crystal ball.
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

int DoWield();

// change stat bonus here for balancing
int StatBonus = 10;

static void create() {
   item::create();
   SetKeyName("ball");
   SetShort("a crystal ball");
   SetId( ({ "ball", "crystal ball" }) );
   SetAdjectives( ({ "crystal"}) );
   SetLong(
	   "This is a beautiful crystal ball. The center"
           " of the ball is very hazy, but it appears"
           " as though a trained eye might be able"
           " to discern the future from it.");
   SetProperty("magic",
     "Amazingly, this an authentic crystal ball. A very few "
     "diviners could 'use' it to scry upon others, though "
     "even those without the sight shouldn't be allowed to hold "
     "it while playing cards.\n"
   );
   SetProperty("history",
     "These were once common tool among diviners, most found now "
     "are now simple spheres of glass, useless for scrying.");
   SetDamageType(BLUNT|MAGIC);
   SetClass(5);
   SetMass(250);
   SetValue(1000);
   SetMaterial( ({ "natural" }) );
   SetDamagePoints(450);
   SetVendorType(VT_TREASURE);

   SetWield( (:DoWield:) );
}

int DoWield() {
  
  if (this_player()->GetClass() == "gypsy") {
    send_messages( "grasp",
      "A swirl of strange landscapes rushes through a crystal "
      "ball's depths as $agent_name $agent_verb it.",
       this_player(), this_object(), environment(this_player())
    );
  } else {
    send_messages( "grasp",
       "The crystal ball turns a cloudy white as $agent_name $agent_verb it.",
       this_player(), this_object(), environment(this_player())
     );
  }
  
  // can't give a skill bonus without the skill, or dumb
  // fighters can learn enchantment spells
  if (this_player()->GetSkillLevel("enchantment")) {
    this_player()->AddSkillBonus("enchantment", StatBonus);
    this_player()->eventPrint("You feel very enchanting!");
  }
  this_player()->AddStatBonus("luck", StatBonus );
  this_player()->eventPrint("You feel lucky!");
  
  return 1;
}

mixed eventUnequip(object who) {
  who->RemoveSkillBonus("enchantment", this_object());
  who->RemoveStatBonus("luck", this_object());

  send_messages("release",
    "The crystal ball's depths clear as $agent_name $agent_verb it.",
    who, this_object(), environment(who) );

  item::eventUnequip(who);
}

mixed eventUse(object who, string args) {
  string what, preposition, jerkname;
  object jerkface;
  object jerkroom;

  debug("here");
  debug(who->GetName());
  if (who->GetClass() != "gypsy") {
    debug("wrong class");
    who->eventPrint("The crystal ball stares back at you all glassy eyed.");
    return 0;
  }

  if (!args || (sizeof(explode(args," ")) < 3) ) {
    who->eventPrint("What? ('use crystal ball to scry on [jerkface]')"); 
    return 0;
  } else {
    sscanf(args, "%s %s %s", what, preposition, jerkname);
  }
  
  if (!what || !(what == "scry")) {
    environment(who)->eventPrint("This ball can only be used to scry, not to "+what+".");
    return 0;
  }
  
  if (!jerkname) {
    environment(who)->eventPrint("Use the crystal ball to scry on who?");
    return 0;
  }

  debug("pre find living: "+jerkname);
  jerkface = find_living(jerkname);
  debug(jerkface);
  
  if (!jerkface ) {
    who->eventPrint("Your gaze cannot reach " + capitalize(jerkname) + ".");
    return 0;
  }

  // I should really make it block /realms but effort
  if (creatorp(jerkface) || jerkface->GetTestChar() ) {
    who->eventPrint(capitalize(jerkname) + " is beyond even your sight.");
    return 0;
  }

  jerkroom = environment(jerkface);
  if (!jerkroom) {
    who->eventPrint("Odd. they seem to be nowhere.");
    return 0;
  }
  
  send_messages("stare",
    "$agent_name $agent_verb crossy eyed at $agent_possessive crystal ball.",
    who, 0, environment(who));

  who->eventPrint("In the depths of the glass you see:\n");
  
  // the magic things
  message("scry",
    jerkroom->GetRemoteDescription(base_name(jerkroom),1),
    who );
  
  return 1;
}
