MUDB/��>���>� secure/include/global.h secure/include/lib.h secure/include/dirs.h secure/include/daemons.h secure/include/dirs.h verbs/players/include/party.h  verbs/players/party.c�  ��!               `   ȓ"��"�����  �  @  @  @  �  �  �  �            !  
 '     .   - 	- 
- 0/@  0z  /@ ,! -  @z /@z //         0@ n& @n 0z  /@ ,1 = + zr  /@z@ /@z@ //         0@  0z  /@ , ! 	 //             0@ , *  @z /@z /         0@ ," .  @z@ /@z@ /         0@ ,@ R : @z@ c<  @z@ c+ !@z@ c /    )         @� z"� /@n& @�n @/@ ,. @ + #@z@ /$@z@ /%@z@ /             0&/.   0   �J     S   #   �w       `�  �   ��  �   ��  *  �� \  ��   %   ȫ   i   `�     ��%%��55�$��!@�h������!X�p���X� `� �����  �  � @� X� ��!�wx� P�!p�!��!��!��!@�!8�!X�!��!��!0�!P�!p�!P���!��!� ��"��        lib/special/verb.c verbs/players/party.c secure/include/global.h secure/include/lib.h secure/include/dirs.h secure/include/daemons.h verbs/players/include/party.h party WRD WRD WRD WRD LIV- You must specify an action, see "help party". GetSleeping" You cannot do that while sleeping! disband /daemon/party CanRemoveParty leave CanLeaveParty  That is an unknown party action. create Not gonna happen. CanCreateParty join CanJoinParty invite leader remove eventRemoveParty eventLeaveParty eventCreateParty eventJoinParty CanInviteMember CanChangeLeader CanRemoveMember
 eventPrint eventInviteMember eventChangeLeader eventRemoveMember�Syntax: <party create PARTY>
        <party disband>
        <party invite PLAYER>
        <party join PARTY>
        <party leader PLAYER>
        <party leave>
        <party remove PLAYER>

This command is the interface to the Dead Souls party system.  A party is simply a group of players who are adventuring together.  The advantage of a party is that it allows people to share the bounties of a quest or other such venture together.

It is important that this party system is extremely different from other party systems.  The first thing is that it does not support the sharing of experience, since players have no experience.  It allows such things as group responses to danger and group completions of quests.  For example, if the party completes a quest, each member of the party is credited with completing the quest.  Note that in order to get such credit, the party must be together upon completion of the quest.

 GetHelp livings_are_remote create can_party_wrd_liv do_party_wrd do_party_wrd_wrd do_party_wrd_liv can_party_wrd can_party_wrd_wrd #global_init#          q  �      q  ?      �              
  
   
#  %  +  ,  
/  1  2  5  7  =  >  
A  D  G  
M  
O  R  
W  Y  \  
b  d  g  j  l  o  p  q  
r  t  w  %z     : � � � ,^�