MUDB�J�E�P�E� secure/include/global.h secure/include/lib.h secure/include/dirs.h include/vehicle.h include/damage_types.h secure/include/daemons.h secure/include/dirs.h  verbs/vehicles/pilot.cD  �K	       X   |��{������  �  <  <  <  8  8  8  D            \   ?     -   , 	 , 
, , , /y
byb�  .�  .� 2 .? .�  .��� @_ ?.�  .?
�� ./y
byby  .y
 .?q�  .��� @_ ?.?
�� ./y
byb�J@T b !�c"cy@�qt �# �$ 22 �%2�$ c  �% ?d� q� +� � | �(�& 'c �)@B�q  d �(* �(+ .M �(, �(- �/. / �(0 �)@B�q 
e    ) @ ^     �@2 �(+ .?
1�� ./y
bybbb  b  b�2 b?   b?  ?  ?
?
 ? @V �3 b?p ? .Sb46�
5  
 �(7 db? 	 �$ @` ���� b�$ 22 �%2�$ c 8�c"cy@�qt �@� dq� +� � � �(�& 9c �)@B�q e �:@�eAE � �(* �(+ �:@�eAE .� �(0 �)@B�q e �:@�eAY S �(; �(< �/. 5 2      2    3    P   > Q    _   g `    d   � �@22 ? �(+ ? �(= �:@�eAE .�# �:�$ �AE ?
>�� ./-   /pt	       �f	 1   �}	 �   �	 �   �	 	  t-	   U  �%�%��55$  �K	��	��	0�	�m	��	xB;���	4�	 �	P	 �	��	�����	 |	t!	lY	(C	�	��	��	\�	����	lR	���,�	� �@'	��	��	��	D��|�	d�	XD	HC	(�	|���v	�C	���(�	������h	�	��, 	n	��	8�	�6	��	H��p�������	lR/������pS	�('�        lib/special/verb.c verbs/vehicles/pilot.c secure/include/global.h secure/include/lib.h secure/include/dirs.h include/vehicle.h include/damage_types.h secure/include/daemons.h pilot dock land STR on STR Sail the ship where??� Syntax: <pilot DIRECTION>
Moves your ship towards the direction you specify. 
See also: takeoff, pirate, hyperjump, board, launch, navigate GetSleeping You are asleep! GetParalyzed You are paralyzed! GetStaminaPoints You are too tired. You are nowhere. PROP_VEHICLE GetProperty You are not in a vehicle! CanPilot GetCrystals* You don't have enough stores to pilot out! CanGo' You should try doing that in a vehicle! CanEnter piloting eventCheckSkill order* $agent_name $agent_verb the vehicle on to  . AddCrystals GetSkillLevel AddStaminaPoints
 GetCapName  hits some space debris.
 eventPrint eventReceiveDamage+ The ship fails to respond to your commands. The ship doesn't move.+ You somehow manage to overload the engines!4 %^RED%^BOLD%^The engines become overloaded.%^RESET%^ engines AddDamagedSystem' The ship hits a large amount of debris.
 eventEnter GetShipEnemies GetPilot /daemon/weather	 GetDomain
 GetRaining* Sailing in such weather is more difficult!! $agent_name $agent_verb the ship   hits some floating debris. eventTrainSkill9 %^BOLD%^RED%^You've managed to damage the drive!%^RESET%^1 %^BOLD%^RED%^The drive has been damaged!%^RESET%^% You fail to evade the ship's enemies. eventGo create can_pilot_str can_pilot_on_str do_pilot_on_str do_pilot_str #global_init#       
    v  �              v  L  �  g  h  i  	j  k  n  r  s  u  v  w  x  y  z  {  |  �  �  �  
�  �  �  �  �  �  �  �  �  �  
�  �  �  
�  �  �  �  �  	�  �  	�  	�  �  	�  $�  �  �  �  �  �  �  �  �  �  	�  
�  �  �  �  	�  �  	�  �  �  	�  �  �  �  �  �  �  �  �  �  �  �  �  �  	�  	�  �  	�  �  �  	�  	�  ?�  �  �  �  �  
�  �  �  d    