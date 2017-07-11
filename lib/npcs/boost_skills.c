string GetBoostSkill(string town, object who) {
  switch (town) {
    case "Arcanith"   :
      return "ice magic";
      break; 
    case "Averath"    :
      return "shock magic";
      break;
    case "Baria"      :
      return "fire magic";
      break;
    case "Dalnairn"   :
      return "poison magic";
      break;
    case "Durgoroth"  :
      return "poison magic";
      break;
    case "Glimmerdin" :
      return "fire magic";
      break;
    case "Grymxoria"  :
      return "ice magic";
      break;
    case "Gwonish"    :
      return "poison magic";
      break;
    case "Gurov"      :
      return "ice magic";
      break;
    case "Haven"      :
      return "fire magic";
      break;
    case "Havenwood"  :
      return "shock magic";
      break;
    case "Jidoor"     :
      return "shock magic";
      break;
    case "Karak"      :
      return "fire magic";
      break;
    case "Keryth"     :
      return "ice magic";
      break;
    case "Kresh"      :
      return "fire magic";
      break;
    case "Lloryk"     :
      return "shock magic";
      break;
    case "Lisht"      :
      if (who->GetRace() == "gnoll") return "poison magic";
      if (who->GetRace() == "elf")   return "fire magic";
      break;
    case "Malveillant":
      return "poison magic";
      break;
    case "Parva"      :
      return "poison magic";
      break;
    case "Soleil"     :
      return "shock magic";
      break;
    case "Sanctum"    :
      return "poison magic";
      break;
    case "Tairi"      :
      return "shock magic";
      break;
    case "Thra"       :
      return "ice magic";
      break;
    case "Underland"  :
      return "shock magic";
      break;
    case "Yozrath"    :
      return "fire magic";
      break;
    default:
      return 0;
    }
}
