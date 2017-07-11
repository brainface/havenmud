#include <lib.h>
inherit LIB_DAEMON;

mapping TownCurrencies = ([
"Averath"     : "ducats",
"Arcanith"    : "senones",
"Baria"       : "chits",
"Dalnairn"    : "shards",
"Durgoroth"   : "crystals",
"Glimmerdin"  : "nuggets",
"Glistendin"  : "glims",
"Grymxoria"   : "bloodgems",
"Gwonish"     : "rounds",
"Gurov"       : "rubles",
"Haven"       : "imperials",
"Havenwood"   : "imperials",
"Jidoor"      : "rupies",
"Karak"       : "orcteef",
"Keryth"      : "senones",
"Kresh"       : "rounds",
"Lisht"       : "deben",
"Lloryk"      : "rounds",
"Malveillant" : "roni",
"Parva"       : "oros",
"Soleil"      : "cuicui",
"Sanctum"     : "imperials",
"Tairi"       : "koken",
"Ungkh"       : "skins",
"Wilderness"  : "imperials",
"Yozrath"     : "dinar",
]);

float GetTownRate(string town) {
  if (!TownCurrencies[town]) {
    error("Invalid town: " + town + " called in CURRENCY_D");
    return -1.0;
    }
  return currency_rate(TownCurrencies[town]);
}

string GetTownCurrency(string town) {
  if (town == "all") return "imperials";
  if (!TownCurrencies[town]) {                                  
    error("Invalid town: " + town + " called in CURRENCY_D");
    return "error";
  }
  return TownCurrencies[town];
}
