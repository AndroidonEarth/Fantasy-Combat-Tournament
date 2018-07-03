# Fantasy Combat Tournament
Simulates a tournament between 2 teams of fantasy fighters.

This game universe contains Vampire, Barbarian, Blue Men, Medusa, and Harry Potter. Each character has attributes of attack, defense, armor, and strength points.

The table containing the attributes data is shown below.

Note: “1d12” means rolling one 12-sided die, and “2d6” means rolling 2 6-sided dice, etc.

| TYPE | ATTACK | DEFENSE | ARMOR | STRENGTH POINTS |
| ---: | :--- | :--- | :--- | :--- |
| Vampire | 1d12 | 1d6\**Charm* | 1 | 18 |
| Barbarian | 2d6 | 2d6 | 0 | 12 |
| Blue Men | 2d10 | 3d6 | 3 | 12\**Mob* |
| Medusa | 2d6\**Glare* | 1d6 | 3 | 8 |
| Harry Potter | 2d6 | 2d6 | 0 | 10/20\**Hogwarts* |

The characters also have their own characteristics as well as special abilities:

| Type | Characterstics | Special Abilities | 
| ---: | :---: | :---: |
| Vampire | Suave, debonair, but vicious and surprisingly resilient. | **Charm:** Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their opponent does not actually attack them. |
| Barbarian | Think Conan or Hercules from the movies. Big sword, big muscles, bare torso. |
| Blue Men | They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies’ armor or clothing. | **Mob:** Blue Men are actually a swarm of small individuals. For every 4 points of damage, they lose one defense die. For example, if they have a strength of 8, they would have 2d6 for defense. |
| Medusa | Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her! | **Glare:** If a Medusa rolls a 12 when attacking then the target instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter on his first life, then Harry Potter comes back to life. |
| Harry Potter | Harry Potter is a wizard. | **Hogwarts:** If Harry Potter's strength reaches 0 or below, he immediately recovers and his total strength becomes 20. If he were to die again, then he’s dead. |







 


Note:


If Medusa uses “glare” on Harry Potter on his first life, then Harry Potter comes back to life after using “hogwarts”.
If the Vampire’s “charm” ability activates when Medusa uses “glare”, the Vampire’s charm trumps Medusa’s glare.
The sample characters are unbalanced intentionally. This will help 
you in debugging your program! Some will win a lot, while others won’t.

 


Gameplay


Each combat between 2 characters ends when one of the characters die.


Each round consists of two attacks, one for each 
character. For each attack, attacker and defender both generate dice 
rolls. The type and number of dice is listed above in the table.


The actual damage inflicted from the attacker onto the defender is calculated as follows:


Damage = attacker’s roll – defender’s roll – defender’s armor


Then the value of that damage is subtracted from the defender’s strength points.


 


Example: character A attacks with dice roll of: 8 10, which means it 
has an attack of 18, and character B defends with dice roll of 5 6, 
which means it has defense of 11, character B also has an armor of 3. So
 the actual damage inflicted from A to B is 18 – 11 – 3 = 4.


If character B has strength point of 8 during that round, the new 
strength point would be 8 – 4 = 4, which means next round B will have 
strength point of 4.


If character B has strength point of 3 during that round, the new 
strength point would be 3 – 4 = -1, which means character B dies.



This game is a one-user-two-player game, so one user should be able to play setup fighters for both teams. For simplicity, we will call the order of fighters in each team “lineup”, like a batting order in baseball or softball.

The flow of gameplay is as follows:

At the start of the tournament, it should prompt the user to enter the number of fighters for both team. After that, for each fighter, the game should ask the user to choose the type of character, and enter a name for the fighter. For example: assume the user chooses Harry Potter for player No.1’s team lineup, the user can name the Harry Potter character “Larry Snotter” or just “Harry Potter No.1”. The game should allow more than 1 of the same character for team lineups. For example, Team A has 3 members: 2 barbarians and 1 Harry Potter. The order of the lineup should be the same as the order user entered.

After the user supplied the lineup of fighters in order, for Team No.1, and Team No.2, the tournament starts. In the tournament, the fighter at the head/front of each lineup will battle, in the same way they fight in project 3. The winner of each fight gets put at the back of their lineup, while loser goes to the top of the loser container (There should only be one containers to hold defeated fighters on both team).

If a fighter won, it may have taken damage, so the game should restore some percentage of the damage they took when they get back in line.

The lineup order cannot be changed, meaning that the game cannot modify the order of the lineup except when putting winner at the back of lineup and loser at the top of the loser container.

The tournament finishes when one of the team does not have any more fighters to fight. When the game ends, it should print the result of the game, and allow user to have the choice to display the contents of the loser pile. More information is shown below in the menu section
