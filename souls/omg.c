#include <lib.h>
inherit LIB_SOUL;

string GetReligionString() {
  switch (this_player()->GetReligion()) {
    case "Aberach" : return "Mistress of Darkness"; break;
    case "Anteky"  : return "Lord on High"; break;
    case "Enniae"  : return "Giver of Breath"; break;
    case "Taisoka" : return "Heavenly Immortals"; break;
    case "Thorian": return "Dominus Pestilentiae"; break;
    case "Rath Cult": return "Emperor of Kailie"; break;
    case "Eclat"   : return "Lady of Mercy";        break;
    case "Kuthar"  : return "Ancestors";            break;
    case "Kylin"   : return "Lord of Order";        break;
    case "Magildan": return "Gods of Magic";        break;
    case "Soirin"  : return "Children of Lies";     break;
    case "Saahagoth": return "Bringer of Chaos"; break;
    case "Damhair"  : return "Master of Storms"; break;
    case "agnostic": return "Gods of Kailie";       break;
    default:         return "Deities Above";        break;
  }
  return "Gods";
}

static void create() {
  ::create();
  SetVerb("omg");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
    ""        : ({ "exclaim", }),
    "LIV"     : ({ "exclaim", }),
    "STR"     : ({ "exclaim", }),
    "STR LIV" : ({ "exclaim", }),
    "LIV STR" : ({ "exclaim", }),
  ]) ),
  SetMessages( ([
    ""        : "$agent_name $agent_verb \"$RELIGION!\"",
    "LIV"     : "$agent_name $agent_verb \"$RELIGION!\" at $target_name.",
    "STR"     : "$agent_name $adverb $agent_verb \"$RELIGION!\"",
    "STR LIV" : "$agent_name $adverb $agent_verb \"$RELIGION!\" at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb \"$RELIGION!\" at $target_name.",
   ]) );
}

string GetMessage(string rule) {
  string tmp = ::GetMessage(rule);
  tmp = replace_string(tmp, "$RELIGION", GetReligionString());
  return tmp;
}
