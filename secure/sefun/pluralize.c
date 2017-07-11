#define VOWELS ({"a","e","i","o","u"})

#define ABNORMAL ([ "moose" : "moose", "mouse" : "mice", "die" : "dice",\
    "index" : "indices", "human" : "humans", "sheep" : "sheep",\
    "dingo" : "dingos", "shaman" : "shamans", "bus" : "busses",\
    "fish" : "fish", "child" : "children", "deer" : "deers",\
    "ox" : "oxen", "drum" : "drums", "plum" : "plums", "goden" : "goden",\
    "lamrani" : "lamrani", "tooth" : "teeth", "wing" : "wings",\
    "are" : "is", "sniff" : "sniffs", "buzz" : "buzzes", "hum" : "hums",\
    "have" : "has", "serf" : "serfs", "pants": "pants",\
    "barf" : "barfs", "focus" : "focuses", "sluff" : "sluffs",\
    "seduce" : "seducing",  "ronin" : "ronin", "fife" : "fifes",\
    "whiff" : "whiffs",\
  ])

string pluralize(mixed single) {
   int x, i, y, ind;
   string str, tmp, tmp1;
   string *words;

  if (!objectp(single) && !stringp(single)) {
    return "";
    }
   if(objectp(single)) {
      if(str = (string)single->query_plural_name()) {
         return str;
      } else str = (string)single->GetKeyName();
  }
  if (stringp(single)) {
      str = (string)single;
    }
   if(!str) return str;
   i = sizeof(words = explode(str, " "));
   if(i > 1 && words[i-1][0] == '(' && words[i-1][<1] == ')') {
      return pluralize(implode(words[1..(i-2)], " " ));
   }
   if(words[0] == "a" || words[0] == "an" || words[0] == "the") {
      i = sizeof(words = words[1..(i-1)]);
   }
   if ((y = member_array("of", words)) > 0 ||
       (y = member_array("Of", words)) > 0 )
   {
      str = words[ind = y-1];
   }
   else
   {
       str = words[ind = i-1];
   }
   x = strlen(str);
   if(ABNORMAL[str]) return ABNORMAL[str];
   if(ABNORMAL[lower_case(str)]) return capitalize(ABNORMAL[lower_case(str)]);
   if(x > 2 && str[x-3..x-1] == "man") {
      words[ind] = str[0..x-3]+"en";
      return implode(words, " ");
   }
   if(x > 1) {
      tmp = str[x-2..x-1];
      switch(tmp) {
         case "ch": case "sh":
            words[ind] = sprintf("%ses", str);
            return implode(words, " ");
         case "ff": case "fe":
            words[ind] = sprintf("%sves", str[0..x-3]);
            return implode(words, " ");
         case "us":
            words[ind] = sprintf("%si", str[0..x-3]);
            return implode(words, " ");
         case "um":
            words[ind] = sprintf("%sa", str[0..x-3]);
            return implode(words, " ");
         case "ef":
            words[ind] = sprintf("%ss", str);
            return implode(words, " ");
      }
   }
   tmp = str[x-1..x-1];
   switch(tmp) {
      case "o": case "x": case "s":
         words[ind] = sprintf("%ses", str);
         return implode(words, " ");
      case "f":
         words[ind] = sprintf("%sves", str[0..x-2]);
         return implode(words, " ");
      case "y":
         if(member_array(str[x-2..x-2],VOWELS)!=-1) {
            words[ind] = sprintf("%ss",str);
         } else words[ind] = sprintf("%sies", str[0..x-2]);
         return implode(words, " ");
   }
   words[ind] = sprintf("%ss", str);
   return implode(words, " ");
}
