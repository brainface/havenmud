/*    /adm/simul_efun/domains.c
 *    from Dead Souls
 *    sefuns for managing domains
 *    created by Descartes of Borg 931204
 */

#include <dirs.h>

void debug(string);

object domain_master(mixed val) {
    if(!val) return 0;
    if(stringp(val)) {
        if(!domain_exists(val)) return 0;
        else return load_object(DOMAINS_DIRS+"/"+val+"/adm/master");
    }
    else if(objectp(val)) {
        if(val = domain(val)) 
          return load_object(DOMAINS_DIRS+"/"+val+"/adm/master");
        else return 0;
    }
    error("Bad argument 1 to load_object().\n");
}

int domain_exists(string dmn) {
    if(!stringp(dmn)) return 0;
    return (file_size(DOMAINS_DIRS+"/"+dmn+"/") == -2);
}

string domain(mixed val) {
    string nom, tmp;

    if(objectp(val) && domain_exists(tmp=(string)val->query_domain())) 
      return tmp;
    else if(stringp(val) && val=load_object(val) &&
      domain_exists(tmp=(string)val->query_domain())) return tmp;
    nom = (objectp(val) ? file_name(val) : (string)val);
    if(sscanf(nom, DOMAINS_DIRS+"/%s/%*s", tmp) == 1) return tmp;
    if(sscanf(nom, REALMS_DIRS+"/%*s/%s/%*s", tmp) == 1 &&
      domain_exists(tmp)) return tmp;
    return 0;
}


string parse_area(string area, string domain) {
  switch(domain) {
    case "averath":
      if (area == "averathroad")    return "on the Averath Road";
      if (area == "bazaar")         return "in the Averath Bazaar";
      if (area == "avfield")         return "in the Barren Fields";
      if (area == "cave")           return "in the Caves";
      if (area == "forest")         return "in the Forest";
      if (area == "glimmerdin")     return "in Glistendin";
      if (area == "mines")          return "in the Mines";
      if (area == "undead")         return "in the Underground Graveyard";
      if (area == "sewers")         return "in the Averath Sewers";
      if (area == "averath")        return "Duchy of Averath";
      if (area == "dalnairn")       return "Dalnairn";
      if (area == "glistendin")     return "Glistendin";
      if (area == "npc")            return "Duchy of Averath";
      if (area == "lumber")         return "by the Abandoned Lumber Camp";
      break;                                 
    case "baria":                            
      if (area == "jungle")         return "in the Jungle";
      if (area == "bariahut")         return "in the Jungle";
      if (area == "tunnel")         return "in the Tunnel under the Jungle";
      if (area == "pyramid")        return "in the Pyramid";
      if (area == "baria")          return "Village of Baria";
      break;                                 
    case "crystal_reaches":                  
      if (area == "aelithol")       return "in Aelithol";
      if (area == "argoth")         return "in Argoth";
      if (area == "camp")           return "in the Gypsy Camp";
      if (area == "caverns")        return "in the Kobold Caverns";
      if (area == "glimmerdinroad") return "on the Glimmerdin Road";
      if (area == "glimmerdintunnel") return "in the Glimmerdin Tunnel";
      if (area == "gurthlad")       return "on the Plains of Gurthlad";
      if (area == "gwonish")        return "in the Gwonish Swamp";
      if (area == "llorykroad")     return "on the road to Lloryk";
      if (area == "mines")          return "in the Dwarf Mines";
      if (area == "rath_tower")     return "in Rath Khan's Tower";
      if (area == "troll_valley")   return "in Troll Valley";
      if (area == "ungkh")          return "in Ungkh";
      if (area == "leatherstore")   return "in the Leather Armour Store in Karak";
      if (area == "lloryk")         return "Lloryk Shire";
      if (area == "karak")          return "Karak-Varn";
      if (area == "glimmerdin")     return "Glimmerdin";
      break;                                 
    case "estergrym":                        
      if (area == "amelia_caves")   return "in a Cave Tunnel";
      if (area == "bog")            return "in the Peat Bog";
      if (area == "fwoods")            return "in the Forbidden Woods";
      if (area == "grymxoria_road") return "on the road to Grymxoria";
      if (area == "kids")           return "in a Clearing";
      if (area == "lake")           return "by the Lake";
      if (area == "northroad")      return "on the North Road";
      if (area == "obsidian")       return "in the Obsidian Apostles Guild Hall";
      if (area == "ogrelair")       return "by the Ogre Lair";
      if (area == "prisoncamp")     return "in the Prison Camp";
      if (area == "skaven")         return "in the Skaven Burrow";
      if (area == "troll_valley")   return "in the Troll Valley";
      if (area == "underdark")      return "in the UnderDark";
      if (area == "grymxoria")      return "Grymxoria";
      if (area == "vacazar")        return "Vacazar";
      if (area == "targoviste")     return "Targoviste";
      if (area == "tower")          return "Mountaintop Tower";
      if (area == "tulu")           return "near the Ruins of Relyah";
      break;                                 
    case "frostmarches":                     
      if (area == "caves")          return "in the Caves";
      if (area == "durgorothroad")  return "on the Durgoroth Road";
      if (area == "frostmarchrd")   return "on the road through the Frostmarches";
      if (area == "frost_mt")       return "near Frost Mountain";
      if (area == "ice")            return "by the Frozen Lake";
      if (area == "icefisher")      return "in the Ice Fishing Shack";
      if (area == "inn")            return "in the Morning Star Inn";
      if (area == "kingdom")        return "in the Faery Kingdom";
      if (area == "lab")            return "in the Keryth Laboratory";
      if (area == "lodge")          return "in the Lodge";
      if (area == "ruins_arcanith") return "in the Ruins of Arcanith";
      if (area == "underkeep")      return "in UnderKeep";
      if (area == "vergoth")        return "in Vergoth";
      if (area == "wood")           return "in the Enchanted Wood";
      if (area == "durgoroth")      return "Durgoroth";
      if (area == "keryth")         return "Keryth";
      if (area == "arcanith")       return "Arcanith";
      if (area == "catacombs")      return "in the Catacombs";
      if (area == "outpost")        return "in the Kylin Outpost";
      if (area == "durg_pit")       return "in the Killing Pit";
      if (area == "outpost_train")  return "in the Training Grounds of the Kylin Outpost";
      if (area == "academy")        return "by the Kobold Fencing Academy";
      break;                                 
    case "gurov":                            
      if (area == "forest")         return "in the Huntsman's Forest";
      if (area == "gurovrd")        return "on the Gurov Road";

      if (area == "taiga")          return "in the Gurovian Taiga";
      if (area == "newbiepath")     return "outside the walls of Gurov";
      if (area == "gurthlad")       return "the Gurov plains";
      if (area == "hospital")       return "the Gurov Hospital";
      if (area == "lagoon")         return "the Icy Lagoon";
      if (area == "gurov")          return "Gurov";
      break;                                 
    case "havenwood":                        
      if (area == "assassin_hall")  return "in the Assassin's Guild Hall";
      if (area == "havenwood")      return "in the Havenwood";
      if (area == "bathhouse")      return "in the Bathhouse";
      if (area == "darkorderguild") return "in the Dark Order Guild Hall";
      if (area == "glen")           return "in the Glen";
      if (area == "gnome_lab")      return "by the Gnome's Lab";
      if (area == "havenwoodroad")  return "on the HavenWood Road";
      if (area == "parvahosp")      return "in the Hospital of Parva";
      if (area == "npc")            return "in the HavenWood";
      if (area == "parvapath")      return "on the Parva Path";
      if (area == "parvaroad")      return "on the Parva Road";
      if (area == "stryke")         return "by Stryke's Lair";
      if (area == "waterfall")      return "by the Waterfall";
      if (area == "wood")           return "in the Coastal Woods";
      if (area == "parva")          return "Parva";
      if (area == "malveillant")    return "Malveillant";
      break;                                 


    case "islands":
      if (area == "assassin")       return "on Assassin Isle";
      if (area == "monkey")         return "on Monkey Island";
      if (area == "forested")       return "on the forested Island";
      if (area == "sheep")          return "on Elban Isle";
      break;
    case "namatar":
      if (area == "namatar")        return "the plains of Namatar";
      break;
    case "peninsula":                       
      if (area == "grove")          return "in the Grove";
      if (area == "npc")            return "near Sanctum";
      if (area == "sulumus")        return "at the Sulumus Trading Post";
      if (area == "wood")           return "in the Fox Glen";
      if (area == "vest")           return "along the Via Esteros";
      if (area == "vimp")           return "along the Via Imperialis";
      if (area == "sanctum")        return "Sanctum";
      break;                                 
    case "planes":
                                    return "Outer Planes";
    case "skicily" :
      if (area == "skicily")        return "in the city of Skicily";

    break;
    case "southern_coast":                   
      if (area == "platemailstore") return "inside the Plate Mail Forge";
      if (area == "acove")          return "at the Pirate Cove";
      if (area == "beornwulf_keep") return "in the Lands of Lord Beornwulf";
      if (area == "camp")           return "in the Bandit Camp";
      if (area == "coffeehouse")    return "in the Twitchy Nymph";
      if (area == "dw")             return "in the Haven Town Cemetery";
      if (area == "havenroad")      return "on the Imperial Road";
      if (area == "kresh")          return "in the Goblin village of Kresh";
      if (area == "mage_tower")     return "in the Haven Mage Tower";
      if (area == "meadow")         return "by Platypus Bay";
      if (area == "wtraveller")     return "in the Weary Traveller Inn";
      if (area == "leatherstore")   return "in the Leather Armour Store by Haven Town";
      if (area == "haven")          return "Haven Town";
      break;     
    case "tairi":                            
      if (area == "hermitage")      return "in the Hermitage";
      if (area == "shrine")         return "in the Shrine";
      if (area == "ninja_tower")    return "in the Ninja Tower";
      if (area == "oni_cave")       return "in the Oni Cave";
      if (area == "mountain")       return "on the Mountain";
      if (area == "camp")           return "in the Ronin Encampment";
      if (area == "tairi_path")     return "on the Tairi Path";
      if (area == "tairi")          return "Tairi";
      if (area == "copse")          return "in the Cherry Blossom Park";
      break;                                 
    case "valley":                           
      if (area == "bazaar")         return "in the Bazaar";
      if (area == "canyon")         return "in the Canyon";
      if (area == "castle")         return "in the Vale Castle";
      if (area == "jidoor_forest")  return "in the Small Forest";
      if (area == "mansion")        return "in the Mansion";
      if (area == "mntside")        return "by the Mountainside";
      if (area == "prasanna")       return "in Prasanna";
      if (area == "ranger_hall")    return "in the Ranger's Guild Hall";
      if (area == "undead_tower")   return "in the Dark Tower";
      if (area == "valley")         return "in the Valley";
      if (area == "jidoor")         return "Jidoor";
      if (area == "underland")      return "Underland";
      if (area == "mount_trog")     return "under Mount Trog";
      if (area == "shining")        return "within the Shining Forest";
      break;                                 
    case "westwood":                         
      if (area == "castle")         return "in the Abandoned Castle";
      if (area == "dunedain_forest")return "in a Small Forest";
      if (area == "enchanted")      return "in an Enchanted Wood";
      if (area == "goblin_camp")    return "in the Goblin Camp";
      if (area == "hiker")          return "in the Hiking Trail";
      if (area == "hospital")       return "in the Eclat Hospital";
      if (area == "monastery")      return "in the Eclat Monastery";
      if (area == "rooklair")       return "by Rook's Lair";
      if (area == "ruins")          return "by the ruins of Ivory Castle";
      if (area == "starvingorcs")   return "in the Orc Camp";
      if (area == "soleilroad")     return "on the Road to Soleil";
      if (area == "westwood")       return "in the Forest";
      if (area == "soleil")         return "Soleil";
      if (area == "npc")            return "in the WestWood";
      if (area == "thra")           return "in the village of Thra";
      break;                                
    case "xandria":
      if (area == "newbie")         return "in the Public Gardens";
      if (area == "mastaba_area")   return "in the Mastaba";
      if (area == "lake")           return "by Lake Rantera";
      if (area == "river")          return "along the River Itro";
      if (area == "desert")         return "in the Xandrian Desert";
      if (area == "lisht")          return "Lisht";
      if (area == "tunnels")        return "in the tunnels under the Xandrian Desert";
      break;
    case "yozrath":                         
      if (area == "gypsycamp")      return "in the Desert Gypsy Camp";
      if (area == "blue_dragon")    return "by Starfire's Lair";
      if (area == "monastery")      return "by the Monastery";
      if (area == "desert")         return "in the Desert";
      if (area == "river")          return "along the Underground River";
      if (area == "yozrath")        return "Yozrath";
      if (area == "npc")            return "Yozrath Desert";
      if (area == "merchant")       return "guarding the Desert Merchant";
      if (area == "minaret")        return "around the Spiral Minaret";
      break; 
    case "innersea":
      return "at sea";
      break;
    case "staff":
      return "roaming the Heavens";
      break;
    case "std":
      return "Around Kailie";
    case "realms":
      return "the Heavens";
    case "save":   // Player Killing
      return "Player Kill -->";
    case "estates":
      return "in a private estate";
  }
  debug("No listed area for " + area + " in " + domain + "!");
  return capitalize(area);
}

string parse_domain(string domain) {
  if (domain == "averath")         return "the Duchy of Averath";
  if (domain == "baria")           return "the Barian Jungle";
  if (domain == "crystal_reaches") return "the Crystal Reaches";
  if (domain == "estergrym")       return "the Estergrym Mountains";
  if (domain == "frostmarches")    return "the FrostMarches";
  if (domain == "gurov")           return "the Principality of Gurov";
  if (domain == "havenwood")       return "the lands around the HavenWood";
  if (domain == "peninsula")       return "the Sanctum Penninsula";
  if (domain == "southern_coast")  return "the Southern Coast";
  if (domain == "tairi")           return "the Land of Tairi";
  if (domain == "valley")          return "the Jidoor Valley";
  if (domain == "westwood")        return "the WestWood";
  if (domain == "innersea")        return "the Inner Sea";
  if (domain == "islands")         return "the Islands of Kailie";
  if (domain == "planes")          return "the Outer Planes";
  if (domain == "staff")           return "the Heavens";
  if (domain == "test")            return "somewhere that should not be";
  if (domain == "xandria")         return "the Kingdom of Xandria";
  if (domain == "yozrath")         return "the Yozrath Desert";
  if (domain == "estates")         return "Private Estate";
  if (domain == "namatar")         return "the Isle of Namatar";
  debug("Bad domain of " + domain);
  return capitalize(domain);
}
