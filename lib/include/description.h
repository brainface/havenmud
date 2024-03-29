mapping Eyes = ([
"daemon"  : ({ "bright yellow", "blood red" }),
"dark-elf"   : ({ "black", "deep blue", "red", }),
"draconian"  : ({ "brown", "black", "green", "red", }),
"dark-dwarf" : ({ "black" }),
"dwarf"      : ({ "brown", "black", }),
"elf"        : ({ "blue", "green", "pale green", "pale blue", "hazel", }),
"gelfling"   : ({ "blue", "green", "hazel", }),
"goblin"     : ({ "red", "black", "green", }),
"goden"      : ({ "red", "yellow", "green", "brown", }),
"gnoll"      : ({ "black", "brown", "gold", }),
"half-elf"   : ({ "brown", "blue", "green", "hazel", "dark brown", }),
"half-orc"   : ({ "light red", "brown", "dark brown", "green" }),
"halfling"   : ({ "brown", "tan", "light brown", "green", }),
"human"      : ({ "brown", "blue", "green", "hazel", }),
"kobold"     : ({ "black", "dark brown" }),
"lamrani"    : ({ "grey", "deep grey", "black", "pitch black", }),
"lizardman"  : ({ "black", "flat black", "beady", "thin" }),
"maralith"   : ({ "black", "red" }),
"muezzin"    : ({ "brown", "dark brown", "black", }),
"nosferatu"  : ({ "black", "red", "deep blue", }),
"ogre"       : ({ "brown" }),
"orc"        : ({ "brown", "red", "light red", "dark red", "dark brown", }),
"skaven"     : ({ "black", "grey", "red", "white", "pink", }),
"sprite"     : ({ "blue", "green", "light blue", }),
"wild-elf"   : ({ "blue", "green", "pale green", "pale blue", "hazel", }),  
]);

mapping Hair = ([
"daemon"     : ({ }), // Deliberately empty. Hairless.
"dark-elf"   : ({ "black", "deep blue", "green", }),
"draconian"  : ({ }), // Deliberately empty.  Hairless.
"dark-dwarf" : ({ "black", "brown", }),
"dwarf"      : ({ "brown", "black", "grey", "dark brown", }),
"elf"        : ({ "blonde", "pale blonde", "pale green", "green", "light brown", }),
"gelfling"   : ({ "brown", "light brown", "green", "blonde", "pale green", }),
"goden"      : ({ "red", "yellow", "green", "brown", "white", "black", "tabby", "calico", }),
"goblin"     : ({ "green", "brown", "black", }),
"gnoll"      : ({ "brown", "dark brown", "black", "grey", "dun" }),
"half-elf"   : ({ "brown", "dark brown", "green", "light brown", "blonde", "dirty blonde", "black", }),
"half-orc"   : ({ "dark green", "brown", "dark brown", "green" }),
"halfling"   : ({ "brown", "tan", "light brown", "black", }),
"human"      : ({ "brown", "blonde", "light brown", "dark brown", "red", "light red", "dirty blonde", "black", }),
"kobold"     : ({ "purple", "dark blue", "magenta", }),
"lamrani"    : ({ }), // Deliberately Empty.  Hairless.
"lizardman"  : ({ }), // They have scales.
"muezzin"    : ({ "brown", "dark brown", "green", }),
"maralith"   : ({ "black" }),
"nosferatu"  : ({ }), // Deliberately Empty.  Hairless.
"ogre"       : ({ "brown", "black" }),
"orc"        : ({ "brown", "dark green", "light green", "green", "dark brown", }),
"skaven"     : ({ "black", "blue-black", "stone-grey", "white", "grey", "bone-white" }),
"sprite"     : ({ "blonde", "light green", "light brown", }),
"wild-elf"   : ({ "blonde", "pale blonde", "pale green", "green", "light brown", }),
]);

mapping SkinTone = ([
"daemon"     : ({ "brownish red", "dark red", "pink", "flat black" }),
"dark-elf"   : ({ "pale", "white", }),
"draconian"  : ({ "brown", "red", "green", "dark red", }), 
"dwarf"      : ({ "brown", "black", }),
"dark-dwarf" : ({ "black", "brown", }),
"elf"        : ({ "pale green", "green", "almond", "pale", }),
"gelfling"   : ({ "pale green", "pale", "light yellow", }),
"goden"      : ({ "red", "yellow", "green", "brown", "white", "black", "tabby", "calico", }),
"goblin"     : ({ "green", "brown", "dark brown", "dark green", }),
"gnoll"      : ({ "brown", "dark brown", "black", "grey", "dun" }),
"half-elf"   : ({ "pale green", "green", "almond", "pale", }),
"half-orc"   : ({ "dark green", "light green", "green", "pale", "pale green", }),
"halfling"   : ({ "tan", "light green", "pale", "pale green", }),
"human"      : ({ "pale", "black", "light yellow", "tanned", "brownish", }),
"kobold"     : ({ "pale blue", "blue", "dark blue", "purple" }),
"lamrani"    : ({ "pale grey", "grey", "deep grey", }), 
"lizardman"  : ({ "black", "brown", "greenish", "dark black" }),
"maralith"   : ({ "pale", "yellow", }),
"muezzin"    : ({ "brown", "dark brown", "green", }),
"nosferatu"  : ({ "pale", "very pale", }), 
"ogre"       : ({ "green", "dark green", "brown", "light green" }),
"orc"        : ({ "brown", "dark green", "light green", "green", }),
"skaven"     : ({ "grey", "pink", "brown", }),
"sprite"     : ({ "light green", "light brown", "pale", "pale green", }),
"wild-elf"   : ({ "pale green", "green", "almond", "pale", }),
]);

mapping SkinType = ([
"daemon"     : ({ "thick", "rough", "rugged", "scaly", "rubbery" }),
"dark-elf"   : ({ "fair", "exotic", }),
"draconian"  : ({ "scaly", }), 
"dwarf"      : ({ "rugged", "rough", "hairy", }),
"dark-dwarf" : ({ "rugged", "rough", "hairy", }), 
"elf"        : ({ "fair", "pale", "fragile", }),
"gelfling"   : ({ "fair", "tanned", }),
"goden"      : ({ "nappy", "thick", "thin", "checkered", "spotted", "short haired", "long haired", }),
"goblin"     : ({ "rough", "lined", "patchy", "lumpy" }),
"gnoll"      : ({ "hairy", "furry", "furred", "fuzzy" }),
"half-elf"   : ({ "fair", "tanned", }),
"half-orc"   : ({ "fair", "tanned", "moldy", "spongy", "matted", }),
"halfling"   : ({ "tanned", "fair", "pale", "ruddy", }),
"human"      : ({ "fair", "tanned", "pale", "lined", "wrinkled", }),
"kobold"     : ({ "matted fur", "thick furred", "furry", "lightly furred", }),
"lamrani"    : ({ "pale", "thin", "hairless", "veined", }), 
"lizardman"  : ({ "scaly", "dry", "leathery", "scaled", "leather scaled" }),
"muezzin"    : ({ "thick", "thin", "matted", "nappy", "furry", "fuzzy", "cuddly", }),
"maralith"   : ({ "pale", "scarred" }),
"nosferatu"  : ({ "fair", "veiny", "gruesome", }), 
"ogre"       : ({ "thick", "rough", "rugged" }),
"orc"        : ({ "moldy", "spongy", "matted",}),
"skaven"     : ({ "furry", "thinly furred", }),
"sprite"     : ({ "small", "petite", "lightweight", }),
"wild-elf"   : ({ "fair", "pale", "fragile", }),
]);

mapping ExtraData = ([
"daemon"     : "large horns curving upwards from $POS head.",
"dark-elf"   : "slightly pointed ears and almond shaped eyes.",
"draconian"  : "an elongated snout with short yellow fangs.", 
"dark-dwarf" : "a stocky build and hair on $POS face.",
"dwarf"      : "a stocky build and hair on $POS face.",
"elf"        : "slightly pointed ears and almond shaped eyes.",
"gelfling"   : "a thin face with wide, expressive eyes.",
"goden"      : "thick fur covering $POS body giving $OBJ a cat-like appearance.",
"goblin"     : "grotesque and exaggerated features, such as extended jaws and a large nose.",
"gnoll"      : "a dog-like snout, sharp canines, and large pointed ears.",
"half-elf"   : "slightly pointed ears with a tiny hint of almond shape to $POS eyes.",
"half-orc"   : "thick hair all over $POS body giving a wild appearance.",
"halfling"   : "thin hair covering $POS body.",
"human"      : 0,
"kobold"     : "a strange smell, like a cross between a wet dog and decaying trash.",
"lamrani"    : "thin skin that is almost translucent and is totally hairless.", 
"lizardman"  : "a lipless mouth with a thin tongue that occassionally flicks out.",
"muezzin"    : "thick fur covering every inch of $POS body.",
"nosferatu"  : "no hair on $POS head and has thin white fangs.",
"ogre"       : 0,
"orc"        : "thick matted hair that lies in patches on $POS body.",
"skaven"     : "thin fur and an elongated, rat-like snout.",
"sprite"     : "sharply pointed ears and long, lithe fingers.",
"wild-elf"   : "slightly pointed ears and almond shaped eyes.",
]);
