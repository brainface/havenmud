#include <lib.h>
#include <damage_types.h>
#include <std.h>
inherit LIB_NPC;

string Summoner;

static void create() {
  ::create();
  SetKeyName("lesser effigy");
  SetId( ({ "effigy" }) );
  SetAdjectives( ({ "lesser" }) );
  SetShort("a lesser effigy");
  SetLong(
    "A lesser effigy is a creature summoned from the Lower Planes that "
    "is a moderate avatar of the faith of the cleric that summoned it. "
    "For each religion, this varies slightly."
    );
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetLevel(60);
  SetMeleeDamageType(BLUNT|MAGIC);
  SetProperty("lesser_effigy", 1);
  SetNoCorpse(1);
  SetDie("%^BOLD%^WHITE%^With a flash, the lesser effigy returns to its home plane.%^RESET%^");
}

string SetSummoner(string summon) { return Summoner = summon; }
string GetSummoner() { return Summoner; }
  
varargs string *SetReligion(mixed str...) {
  string *rel = ::SetReligion(str...);
  object obj, obj2, obj3, obj4;
  switch(GetReligion()) {
    case "Aberach":
      SetRace("demon");
      SetMorality(-1000);
      SetLong( GetRawLong() +
        " This large human-looking being has a pale complexion.  His long, "
        "straight hair is jet black, and hangs down to nearly shoulder length. "
        "The being has fierce eyes that seem to alter between deeply blood red "
        "and an intense icy blue depending on the light."
        );
      SetShort("a demonic lesser effigy of Aberach");
      SetGender("male");
      SetAdjectives( ({ "demonic", "lesser", "aberach" }) );
      obj = new(STD_SPELLS + "obj/aberach_effigy_sword");
      if (obj) obj->eventMove(this_object());
      SetFirstCommands("wield sword");
      call_out( (: eventForce, "wield sword" :), 0);
      break;
    case "Eclat":
      SetRace("demon");
      SetMorality(1000);
      SetLong( GetRawLong() +
        " This creature is large and covered in a strange mixture of fur and "
        "a greenish plantlike substance. A mosslike covering seems to grow "
        "in patches where the fur does not."
        );
      SetShort("a forest-dwelling lesser effigy of Eclat");
      SetAdjectives( ({ "lesser", "forest", "dwelling", "eclat" }) );
      break;
    case "Kylin":
      SetRace("demon");
      SetMorality(1000);
      AddLimb("right wing", "torso", 4);
      AddLimb("left wing", "torso", 4);
      SetLong( GetRawLong() +
        " This pure white creature stands with a pale glow about it. "
        "From its eyes of pure gold, a cold stare that is resplendant "
        "of martial glory and magic penetrates the soul of those around."
        );
      SetShort("a pure white lesser effigy of Kylin");
      SetAdjectives( ({ "pure", "white", "lesser", "kylin" }) );
      SetSkill("faith",120,1);
      SetSkill("enchantment",120,1);
      SetSpellBook( ([
        "wall of force" : 100,
      ]) );
      SetCombatAction(4, ({ "!cast wall of force" }) );
      SetFirstCommands( ({ "cast wall of force" }) );
      break;
    case "Soirin":
      SetRace("demon");
      SetMorality(-1000);
      SetLong( GetRawLong() +
        " This lithe female creature appears to be some form of dark-elf, though "
        "larger and somehow oddly unnatural. The creature moves with a preternatural "
        "speed and with an alluring style of movement that distracts those around "
        "from fulfilling their own desires."
        );
      SetShort("a stunningly seductive lesser effigy of Soirin");
      SetGender("female");
      SetAdjectives( ({ "stunningly", "seductive", "soirin" }) );
      break;
    case "Saahagoth":
      SetRace("maralith");
      SetMorality(-1000);
      SetLong( GetRawLong() +
        " This hidiously ugly create appears to be some sort of demon akin to a "
        "maralith. It reeks of chaos and sulfer and is covered in burn marks. "
        "Her black eyes give a cold emotionless stare of disdain about the world "
        "around her."
        );
      SetShort("a chaotic lesser effigy of SaaHaGoth");
      SetGender("female");
      SetAdjectives( ({ "chaotic", "saahagoth" }) );     
      SetInventory( ([
         "/std/weapon/blunt/war-hammer" : "wield hammer in lower left hand",
         "/std/weapon/hack/hand-axe" : "wield first axe in lower right hand",
         "/std/weapon/slash/bluesword" : "wield longsword in upper left hand",
         "/std/weapon/slash/shortsword" : "wield shortsword in middle left hand",
         "/std/weapon/blunt/mace" : "wield mace in middle right hand",
         "/std/weapon/blunt/copper_club" : "wield club in upper right hand",
      ]) );
      obj = new("/std/weapon/blunt/war-hammer");
      if (obj) obj->eventMove(this_object());
      SetFirstCommands("wield hammer in lower left hand");
      call_out( (: eventForce, "wield hammer in lower left hand" :), 0);
      obj2 = new("/std/weapon/hack/hand-axe");
      if (obj2) obj2->eventMove(this_object());
      SetFirstCommands("wield axe in lower right hand");
      call_out( (: eventForce, "wield axe in lower right hand" :), 0);
      obj3 = new("/std/weapon/slash/bluesword");
      if (obj3) obj3->eventMove(this_object());
      SetFirstCommands("wield longsword in upper left hand");
      call_out( (: eventForce, "wield longsword in upper left hand" :), 0);
      obj4 = new("/std/weapon/slash/shortsword");
      if (obj4) obj4->eventMove(this_object());
      SetFirstCommands("wield shortsword in upper right hand");
      call_out( (: eventForce, "wield shortsword in upper right hand" :), 0);
      break;
    case "Thorian":
      SetRace("elemental");
      SetMorality(-500);
      SetShort("a shambling Thorian horror");
      SetId( ({ "horror", "elemental", "effigy" }) );
      SetKeyName("Thorian Horror");
      SetAdjectives( ({ "lesser", "shambling", "Thorian" }) );
      SetLong(GetRawLong() + " This glob of brown goo appears to be a slimy indicator of disease of evil.");
      SetSkill("faith", 200, 1);
      SetSkill("necromancy", 200, 1);
      SetCombatAction(10, ({ "!cast major venemous touch", "!cast minor venemous touch"  }) );
      SetMessage("leave", "$N shambles and oozes $D.");
      SetMessage("come", "$N shambles and oozes in.");
      break;
    default:
      debug("Called for religion of " + GetReligion() + " in lesser effigy!");
      break;
    }
    return ({ GetReligion() });
}
  
void heart_beat() {
  ::heart_beat();
  if (!Summoner) return;
  if (!find_living(Summoner)) {
    if (environment()) {
      eventForce("yell I return to my home, my duties complete.");
    }
    eventDestruct();
  }
}

