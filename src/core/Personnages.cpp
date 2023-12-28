#include <iostream>
#include <stdio.h>
#include "Personnages.h"

using namespace std;

void Personnages::RemplirDialogue(){

    //DIALOGUES DE LA QUETES 1 :
    //PERSONNAGE NUMERO 0 : Castiel GraineDeCafeMauvaisGarcon
    personnages[0].dialogues[0][0] = "Pousse toi tu bloque le passage !"; //1er dialogue du garcon 0
    personnages[0].dialogues[0][1] = "*l'ignorer*"; 
    personnages[0].dialogues[0][2] = "Super l'acceuil"; //2eme reponse
    personnages[0].dialogues[0][3] = "Saurais-tu ou pourrais-je regler les frais d'inscriptions de l'AML?"; //3eme reponse

    personnages[0].dialogues[1][0] = "Est ce qu'il y a ecrit guide de campus sur ma tronche ? Je suis le grand Okechukwu Lumumba"; //2e dialogue du garcon 0
    personnages[0].dialogues[1][1] = "*l'ignorer*"; //1ere reponse
    personnages[0].dialogues[1][2] = "*partir en pleurant parce qu'il est trop mechant et tu as besoin de douceur*"; //2eme reponse
    personnages[0].dialogues[1][3] = "Je vais t'appeler Oke ok ?"; //3eme reponse

    personnages[0].dialogues[2][0] = "Si t'es pas contente c'est la meme ok ?"; //2e dialogue du garcon 0
    personnages[0].dialogues[2][1] = "Ok Oke"; //1ere reponse
    personnages[0].dialogues[2][2] = "*partir en pleurant*"; //2eme reponse
    personnages[0].dialogues[2][3] = "*lui donner une claque*"; //3eme reponse

    // ADAM
    personnages[1].dialogues[0][0] = "Tu as l'air perdue hihi"; //1er dialogue du garcon 1
    personnages[1].dialogues[0][1] = "Mele toi de tes affaires"; //1ere reponse
    personnages[1].dialogues[0][2] = "Non tout va bien"; //2eme reponse
    personnages[1].dialogues[0][3] = "Oui sais-tu ou regler les frais d'incriptions de l'AML?"; //3eme reponse

    personnages[1].dialogues[1][0] = "Si tu cherches le reponsable de l'AML c'est Karim hihi"; //1er dialogue du garcon 1
    personnages[1].dialogues[1][1] = "Enfin quelqu'un qui le dis"; //1ere reponse
    personnages[1].dialogues[1][2] = "Ok"; //2eme reponse
    personnages[1].dialogues[1][3] = "Azy je decale eh merce le sang"; //3eme reponse

    personnages[1].dialogues[2][0] = "Hihi"; //1er dialogue du garcon 1
    personnages[1].dialogues[2][1] = "*partir*"; //1ere reponse
    personnages[1].dialogues[2][2] = "*partir vite*"; //2eme reponse
    personnages[1].dialogues[2][3] = "*lui donner une claque parce qu'il m'a soule avec ses hihi*"; //3eme reponse


    // KARIM
    personnages[2].dialogues[0][0] = "Oh tu a retrouve ton dossier... Je t'attendais..."; //1er dialogue du garcon 1
    personnages[2].dialogues[0][1] = "Oui il etait au toilettes parce que j'ai mange trop de casssoulet maghrebin. Qui es-tu ?"; //1ere reponse
    personnages[2].dialogues[0][2] = "Oue tiens mais t'es qui wesh ?"; //2eme reponse
    personnages[2].dialogues[0][3] = "Desole de t'avoir fait attendre...Je peux savoir qui tu es ?"; //3eme reponse

    personnages[2].dialogues[1][0] = "Je...je...m'appelle Karim..."; //1er dialogue du garcon 1
    personnages[2].dialogues[1][1] = "Ah oue le fameux Kaka"; //1ere reponse
    personnages[2].dialogues[1][2] = "Tu begayes beaucoup machaAllah"; //2eme reponse
    personnages[2].dialogues[1][3] = "Eh bah je te cherchais aussi"; //3eme reponse

    personnages[2].dialogues[2][0] = "Du coup...je vais m'occuper de ton dossier...si tu le permets bien sur..."; //1er dialogue du garcon 1
    personnages[2].dialogues[2][1] = "Merci beaucoup qu'Allah te facilite ;) *lui donner gentiment*"; //1ere reponse
    personnages[2].dialogues[2][2] = "Oue tiens *lui jeter le dossier*"; //2eme reponse
    personnages[2].dialogues[2][3] = "*lui donner et partir sans un mot comme une malpropre, malpolie qui reussir rien dans sa vie*"; //3eme reponse


    // DESSERREE
    personnages[3].dialogues[0][0] = "Que fait-tu ici ? Tu devrais travailler sur ton projet !"; //1er dialogue du garcon 1
    personnages[3].dialogues[0][1] = "Tranquillou bilou on a encore jusqu'au 1er mai"; //1ere reponse
    personnages[3].dialogues[0][2] = "OH NON ! J'avais oublie"; //2eme reponse
    personnages[3].dialogues[0][3] = "Je suis pas un bebe je sais ce que je dois faire merci."; //3eme reponse

    personnages[3].dialogues[1][0] = "Je commence remttre en question ton serieux"; //1er dialogue du garcon 1
    personnages[3].dialogues[1][1] = "NON ! C'est juste que j'ai ap le temps en ce moment parce que je travaille a l'usine"; //1ere reponse
    personnages[3].dialogues[1][2] = "Pensez ce que vous voulez"; //2eme reponse
    personnages[3].dialogues[1][3] = "Il faut savoir que je travaille tres dur"; //3eme reponse

    personnages[3].dialogues[2][0] = "Ecoute, c'est simple si tu rends rien je vais te mettre 0"; //1er dialogue du garcon 1
    personnages[3].dialogues[2][1] = "Vous recevrez notre projet en temps et en heure"; //1ere reponse
    personnages[3].dialogues[2][2] = "C'est bon je vais allez travailler tout de suite"; //2eme reponse
    personnages[3].dialogues[2][3] = "Quoi ? Ca se fait pas moi je dis"; //3eme reponse

    // KARIM
    personnages[2].dialogues[3][0] = "Bienvenue a l'AML..."; //1er dialogue du garcon 1
    personnages[2].dialogues[3][1] = "*l'ignorer*"; //1ere reponse
    personnages[2].dialogues[3][2] = "Oue oue merci"; //2eme reponse
    personnages[2].dialogues[3][3] = "*wah en vrai il est trop cute*"; //3eme reponse

    personnages[2].dialogues[4][0] = "Euh...Salam Aleykom... *baisse les yeux*"; //1er dialogue du garcon 1
    personnages[2].dialogues[4][1] = "Wesh trkl ou kwa"; //1ere reponse
    personnages[2].dialogues[4][2] = "kestuveux wesh"; //2eme reponse
    personnages[2].dialogues[4][3] = "Wa aleykom salem"; //3eme reponse

    personnages[2].dialogues[5][0] = "Fait comme chez toi...et n'hesite pas si tu as un souci..."; //1er dialogue du garcon 1
    personnages[2].dialogues[5][1] = "Ah c'est gentil merci !"; //1ere reponse
    personnages[2].dialogues[5][2] = "Tu begayes beaucoup machaAllah"; //2eme reponse
    personnages[2].dialogues[5][3] = "*l'ignorer et allez faire une sieste sur le canape comme une grosse puante*"; //3eme reponse

    // LA PESTE
    personnages[4].dialogues[0][0] = "Je t'ai vu parler a mon Oke d'amour"; //1er dialogue du garcon 1
    personnages[4].dialogues[0][1] = "Change tes lunettes ma belle"; //1ere reponse
    personnages[4].dialogues[0][2] = "Oke ne t'appartiens pas ok"; //2eme reponse
    personnages[4].dialogues[0][3] = "Bouge de mon chemin la haramiste"; //3eme reponse

    personnages[4].dialogues[1][0] = "Tu ne sais rien de mon petit bout de chou, on est voisins, on habite au quais"; //1er dialogue du garcon 1
    personnages[4].dialogues[1][1] = "Pourquoi tu me raconte ta vie de nullos"; //1ere reponse
    personnages[4].dialogues[1][2] = "Oke"; //2eme reponse
    personnages[4].dialogues[1][3] = "Tu parles beaucoup machaAllah"; //3eme reponse

    personnages[4].dialogues[2][0] = "Pff de toute facon il n'a d'yeux que pour moi donc je ne m'inquiete pas"; //1er dialogue du garcon 1
    personnages[4].dialogues[2][1] = "*un jour je vais la balaye celle la*"; //1ere reponse
    personnages[4].dialogues[2][2] = "Bah pourquoi tu viens me parler wesh"; //2eme reponse
    personnages[4].dialogues[2][3] = "'La bave du vieux cochon qui pue n'atteint pas la blanche colombe'"; //3eme reponse

    // OKE 
    personnages[0].dialogues[3][0] = "Pourquoi tu reviens me souler ?"; //1er dialogue du garcon 0
    personnages[0].dialogues[3][1] = "Ca va mon petit bout de chou"; //1ere reponse
    personnages[0].dialogues[3][2] = "Mon petit quais prefere"; //2eme reponse
    personnages[0].dialogues[3][3] = "Le plus beau de sa generation"; //3eme reponse

    personnages[0].dialogues[4][0] = "Ta facon de parler me rapelle vite fait quelqu'un mais je vois pas qui"; //2e dialogue du garcon 0
    personnages[0].dialogues[4][1] = "J'ai essayer de parler comme ta meuf"; //1ere reponse
    personnages[0].dialogues[4][2] = "J'ai croise une fille qui se presente comme ta petite amie c'est pas vrai ein ?"; //2eme reponse
    personnages[0].dialogues[4][3] = "Le boug il a une meuf il la reconnais meme pas quand je l'imite (la honte)"; //3eme reponse

    personnages[0].dialogues[5][0] = "C'est plus ma meuf"; //2e dialogue du garcon 0
    personnages[0].dialogues[5][1] = "Ok Oke merci"; //1ere reponse
    personnages[0].dialogues[5][2] = "Je vais la retrouver au quais merci Oke"; //2eme reponse
    personnages[0].dialogues[5][3] = "J'en etais sure je vais la retrouver je vais la meler"; //3eme reponse


    // LA PESTE
    personnages[4].dialogues[3][0] = "..."; //1er dialogue du garcon 1
    personnages[4].dialogues[3][1] = "Ca va la mantheuse ? "; //1ere reponse
    personnages[4].dialogues[3][2] = "Comment elle va la grosse mytho"; //2eme reponse
    personnages[4].dialogues[3][3] = "C'est haram de mentir"; //3eme reponse

    personnages[4].dialogues[4][0] = "J'ai jamais menti de toute ma life wesh et je ne mentirais jamais"; //1er dialogue du garcon 1
    personnages[4].dialogues[4][1] = "Tu veux qu'on ramene ton bout de chou pour voir ?"; //1ere reponse
    personnages[4].dialogues[4][2] = "Meme quand tu as dit que Oke etais okay avec le fait que vous soyez un couple ?"; //2eme reponse
    personnages[4].dialogues[4][3] = "Elle va se calmer la reine des neige, j'ai parle a Oke"; //3eme reponse

    personnages[4].dialogues[5][0] = "La roue tourne ma belle...la roue tourne"; //1er dialogue du garcon 1
    personnages[4].dialogues[5][1] = "Ah oue cho"; //1ere reponse
    personnages[4].dialogues[5][2] = "Allez bye"; //2eme reponse
    personnages[4].dialogues[5][3] = "Va te faire ecraser par ta vieille roue"; //3eme reponse

    // DESSEREE
    personnages[3].dialogues[3][0] = "J'ai cru entendre par des sources inconnues que tu aurais triche au CCF de LIFAPSD"; //1er dialogue du garcon 1
    personnages[3].dialogues[3][1] = "Vos \"sources inconnue\" ne serais pas blonde avec des lunettes par hasard ?"; //1ere reponse
    personnages[3].dialogues[3][2] = "Qui veut ma peau wesh ?"; //2eme reponse
    personnages[3].dialogues[3][3] = "C'est qui exactement vos \"sources inconnue\""; //3eme reponse

    personnages[3].dialogues[4][0] = "La source n'est pas importante ici. As-tu vraiment triche ?"; //1er dialogue du garcon 1
    personnages[3].dialogues[4][1] = "Promis jure crache"; //1ere reponse
    personnages[3].dialogues[4][2] = "Bah non wesh jamais de la life"; //2eme reponse
    personnages[3].dialogues[4][3] = "Bien-sur que non voyons"; //3eme reponse
    
    personnages[3].dialogues[5][0] = "Ce n'est pas une blague, si ca se confirme tu devras rembourser ta bourse"; //1er dialogue du garcon 1
    personnages[3].dialogues[5][1] = "Comment vais-je faire, je suis pauvre !"; //1ere reponse
    personnages[3].dialogues[5][2] = "Oh non c'est cacastrophe"; //2eme reponse
    personnages[3].dialogues[5][3] = "Oh non mon compte il est aussi sec que Arouf Gangsta"; //3eme reponse

    // LA PESTE 
    personnages[4].dialogues[6][0] = "Qu'est ce que tu me veux encore la tricheuse ?"; //1er dialogue du garcon 1
    personnages[4].dialogues[6][1] = "Je me disais bien aussi que c'etait toi"; //1ere reponse
    personnages[4].dialogues[6][2] = "Je savais que c'etait toi"; //2eme reponse
    personnages[4].dialogues[6][3] = "Pff tu as donc rien a faire de ta life"; //3eme reponse

    personnages[4].dialogues[7][0] = "Je vois pas de quoi tu parles tu devrais plutot t'inquieter pour toi ma pauvre (litteralement)"; //1er dialogue du garcon 1
    personnages[4].dialogues[7][1] = "Deja je suis pas pauvre, je suis riche de l'interieur"; //1ere reponse
    personnages[4].dialogues[7][2] = "Oue j'avoue je suis un peu inquiete la"; //2eme reponse
    personnages[4].dialogues[7][3] = "Non t'inquiete je m'inquiete pas ein, je peut rembourser ma bourse maintenant si j'ai envie (mensonge)"; //3eme reponse

    personnages[4].dialogues[8][0] = "Tu sais tu devrais revoir tes frequentations je dis ca je dis rien..."; //1er dialogue du garcon 1
    personnages[4].dialogues[8][1] = "Qu'est ce que tu veux dire par la ?"; //1ere reponse
    personnages[4].dialogues[8][2] = "Ein ??"; //2eme reponse
    personnages[4].dialogues[8][3] = "Quels frequenations j'ai pas d'amis wesh ??"; //3eme reponse

    // OKE 
    personnages[0].dialogues[6][0] = "Wesh bien ou bien"; //1er dialogue du garcon 0
    personnages[0].dialogues[6][1] = "*l'ignorer*"; //1ere reponse
    personnages[0].dialogues[6][2] = "Je suis pas d'humeur la"; //2eme reponse
    personnages[0].dialogues[6][3] = "Laisse moi tranquille"; //3eme reponse

    personnages[0].dialogues[7][0] = "Je m'en fout mais je vais quand meme demander. Qu'est ce qu'il y a"; //2e dialogue du garcon 0
    personnages[0].dialogues[7][1] = "*lui expliquer la situation*"; //1ere reponse
    personnages[0].dialogues[7][2] = "*lui expliquer la situation en lachant mes nerfs sur lui*"; //2eme reponse
    personnages[0].dialogues[7][3] = "*lui expliquer la situation calmement"; //3eme reponse

    personnages[0].dialogues[8][0] = "Parle pas moi la tricheuse"; //2e dialogue du garcon 0
    personnages[0].dialogues[8][1] = "Mais j'ia pas triche wesh"; //1ere reponse
    personnages[0].dialogues[8][2] = "T'es vraiment trop nul"; //2eme reponse
    personnages[0].dialogues[8][3] = "Quel homme incapable"; //3eme reponse

    // ADAM
    personnages[1].dialogues[3][0] = "Bah pourquoi tu tire cette tronche hihi"; //1er dialogue du garcon 1
    personnages[1].dialogues[3][1] = "Mele toi de tes affaires"; //1ere reponse
    personnages[1].dialogues[3][2] = "Pas tes oignons"; //2eme reponse
    personnages[1].dialogues[3][3] = "Laisse moi tranquille hihi"; //3eme reponse

    personnages[1].dialogues[4][0] = "Comme tu veux hihi"; //1er dialogue du garcon 1
    personnages[1].dialogues[4][1] = "*lui expliquer la situation*"; //1ere reponse
    personnages[1].dialogues[4][2] = "*lui expliquer la situation en lachant mes nerfs sur lui*"; //2eme reponse
    personnages[1].dialogues[4][3] = "*lui expliquer la situation calmement*"; //3eme reponse

    personnages[1].dialogues[5][0] = "..."; //1er dialogue du garcon 1
    personnages[1].dialogues[5][1] = "*il a pas dit hihi c'est bizarre*"; //1ere reponse
    personnages[1].dialogues[5][2] = "*pourquoi il me repond pas c'est bizarre*"; //2eme reponse
    personnages[1].dialogues[5][3] = "*azy il nous fait le dark sasuke maintenant*"; //3eme reponse

    // KARIM 
    personnages[2].dialogues[6][0] = "Tu m'a l'air... patrac"; //1er dialogue du garcon 1
    personnages[2].dialogues[6][1] = "C'est toi le patrac"; //1ere reponse
    personnages[2].dialogues[6][2] = "*soupirer*"; //2eme reponse
    personnages[2].dialogues[6][3] = "Oue ca va pas trop"; //3eme reponse

    personnages[2].dialogues[7][0] = "Euh...qu'est ce qu'il se passe ?? *baisse les yeux*"; //1er dialogue du garcon 1
    personnages[2].dialogues[7][1] = "*lui expliquer la situation*"; //1ere reponse
    personnages[2].dialogues[7][2] = "*lui expliquer la situation lachant mes nerfs sur lui*"; //2eme reponse
    personnages[2].dialogues[7][3] = "*lui expliquer la situation calmement*"; //3eme reponse

    personnages[2].dialogues[8][0] = "Pour prouver que tu n'a pas triche tu peux allez a la salle info de la bu et cherchez la cle usb qui ets relie aux cameras des salles d'exam"; //1er dialogue du garcon 1
    personnages[2].dialogues[8][1] = "T'es le meilleur j'avais perdu espoir avec tout ces incapable MERCI BEAUCOUP"; //1ere reponse
    personnages[2].dialogues[8][2] = "J'y vais merci"; //2eme reponse
    personnages[2].dialogues[8][3] = "*partir viiiiiiite*"; //3eme reponse

    // CHAIMA 
    personnages[5].dialogues[0][0] = "Salam Aleykom ma soeur tu as un probleme ?"; //1er dialogue du garcon 1
    personnages[5].dialogues[0][1] = "Non tout roule al hamdoulillah"; //1ere reponse -5
    personnages[5].dialogues[0][2] = "Wa 3aleykum Salam, non"; //2eme reponse 0
    personnages[5].dialogues[0][3] = "Wa 3aleykum salam OukhtyFuzeTea"; //3eme reponse 5

    personnages[5].dialogues[1][0] = "Azy dis moi tout"; //1er dialogue du garcon 1
    personnages[5].dialogues[1][1] = "J'ai des envies de meurtres contre les gens qui mettent des mots de passe a leur cle usb sinon trkl"; //1ere reponse
    personnages[5].dialogues[1][2] = "Laisse tomber faut que je trouve une crack en piaratage de cle usb"; //2eme reponse
    personnages[5].dialogues[1][3] = "Cette cle usb a un mot de passe et je dois absolument voir ce qu'il y a dedans"; //3eme reponse

    personnages[5].dialogues[2][0] = "Azy laisse moi faire j'ai vu des tutos sur le YouTube"; //1er dialogue du garcon 1
    personnages[5].dialogues[2][1] = "Gratteuse de hasannets je ferais des duaa pour toi"; //1ere reponse
    personnages[5].dialogues[2][2] = "Merciiiiii"; //2eme reponse
    personnages[5].dialogues[2][3] = "Azyyyy"; //3eme reponse

    // DESSEREE
    personnages[3].dialogues[6][0] = "Oula miss je respire le meme air qu'une tricheuse honte a moi"; //1er dialogue du garcon 1
    personnages[3].dialogues[6][1] = "Le mensonge prend l'ascenseur et la verite prend l'escalier"; //1ere reponse
    personnages[3].dialogues[6][2] = "La medisance est puni par la loi"; //2eme reponse
    personnages[3].dialogues[6][3] = "Je viens vous amener la preuve du contraire"; //3eme reponse

    personnages[3].dialogues[7][0] = "Oh je suis curieuse fais moi voir ca"; //1er dialogue du garcon 1
    personnages[3].dialogues[7][1] = "*lui donner*"; //1ere reponse
    personnages[3].dialogues[7][2] = "*lui jeter a la figure comme un malpropre qui aura des mauavaises notes*"; //2eme reponse
    personnages[3].dialogues[7][3] = "*lui donner gentiment*"; //3eme reponse

    personnages[3].dialogues[8][0] = "Je n'ai jamais affirme quoi que ce soit"; //1er dialogue du garcon 1
    personnages[3].dialogues[8][1] = "Vous l'avez acheter ou votre magnifique veste (reversible)"; //1ere reponse
    personnages[3].dialogues[8][2] = "Allez ok"; //2eme reponse
    personnages[3].dialogues[8][3] = "*dire tout bas* hypocrite"; //3eme reponse

    // LA PESTE 
    personnages[4].dialogues[9][0] = "Pourquoi tu me colle comme ca va t'acheter des amis"; //1er dialogue du garcon 1
    personnages[4].dialogues[9][1] = "Ca s'achete ou ?"; //1ere reponse
    personnages[4].dialogues[9][2] = "J'ai pas besoin d'amis moi d'abord"; //2eme reponse
    personnages[4].dialogues[9][3] = "Tais toi j'ai pleins d'amis moi d'abord"; //3eme reponse

    personnages[4].dialogues[10][0] = "J'ai pas le temps pour tes sottises"; //1er dialogue du garcon 1
    personnages[4].dialogues[10][1] = "J'ai prouve mon innocence en tout cas grace a la cle usb de la salle info"; //1ere reponse
    personnages[4].dialogues[10][2] = "Au moins j'ai une cle usb rose qui m'a sauve"; //2eme reponse
    personnages[4].dialogues[10][3] = "Ma journee a ete sauve par une cle usb rose"; //3eme reponse

    personnages[4].dialogues[11][0] = "Quoi ?? Donne moi cette cle usb TOUT DE SUITE"; //1er dialogue du garcon 1
    personnages[4].dialogues[11][1] = "Oula calmos amigos"; //1ere reponse
    personnages[4].dialogues[11][2] = "*pourquoi elle panique comme ca*"; //2eme reponse
    personnages[4].dialogues[11][3] = "*partir en courant*"; //3eme reponse

    // ADAM
    personnages[1].dialogues[6][0] = "Je dois t'avouer quelque chose"; //1er dialogue du garcon 1
    personnages[1].dialogues[6][1] = "Je ne suis pas interessee deso hihi"; //1ere reponse
    personnages[1].dialogues[6][2] = "Hihi ?"; //2eme reponse
    personnages[1].dialogues[6][3] = "Qu'est ce qu'il a light yagami"; //3eme reponse

    personnages[1].dialogues[7][0] = "C'est pas ca c'est juste que c'est moi qui ai dit a Mme Desseree que tu avais triche"; //1er dialogue du garcon 1
    personnages[1].dialogues[7][1] = "Quoi ?? Pourquoi ??"; //1ere reponse
    personnages[1].dialogues[7][2] = "T'es serieux la ?? Avec ta tete la. Pourquoi meme ??"; //2eme reponse
    personnages[1].dialogues[7][3] = "*ne rien dire*"; //3eme reponse

    personnages[1].dialogues[8][0] = "J'etais jaloux parce que tu as une meilleure note que moi desole..."; //1er dialogue du garcon 1
    personnages[1].dialogues[8][1] = "*partir*"; //1ere reponse
    personnages[1].dialogues[8][2] = "*l'insulter*"; //2eme reponse
    personnages[1].dialogues[8][3] = "*l'insulter et partir*"; //3eme reponse

    // OKE 
    personnages[0].dialogues[9][0] = "Eh je voulais te dire, je t'ai pas cru bah skuze"; //1er dialogue du garcon 0
    personnages[0].dialogues[9][1] = "Des excuses dignes d'un incapable"; //1ere reponse
    personnages[0].dialogues[9][2] = "Ok Oke"; //2eme reponse
    personnages[0].dialogues[9][3] = "Mmh"; //3eme reponse

    personnages[0].dialogues[10][0] = "Rho ca va, t'a quoi dans la main"; //2e dialogue du garcon 0
    personnages[0].dialogues[10][1] = "Je sais pas devine"; //1ere reponse
    personnages[0].dialogues[10][2] = "Ca se voit pas tu veux des lunettes ?"; //2eme reponse
    personnages[0].dialogues[10][3] = "Une cle usb"; //3eme reponse

    personnages[0].dialogues[11][0] = "Ouch et pourquoi tu as ca ?"; //2e dialogue du garcon 0
    personnages[0].dialogues[11][1] = "Pour la bouffer"; //1ere reponse
    personnages[0].dialogues[11][2] = "Pas tes affaires"; //2eme reponse
    personnages[0].dialogues[11][3] = "*l'ignorer*"; //3eme reponse

    // OKE 
    personnages[0].dialogues[12][0] = "Alors tu as decouvert quelque chose d'interessant avec cette cle usb ?"; //1er dialogue du garcon 0
    personnages[0].dialogues[12][1] = "Parle moi pas oke"; //1ere reponse
    personnages[0].dialogues[12][2] = "Pas tes affaires"; //2eme reponse
    personnages[0].dialogues[12][3] = "Oue assez"; //3eme reponse

    personnages[0].dialogues[13][0] = "Allez fait voir la"; //2e dialogue du garcon 0
    personnages[0].dialogues[13][1] = "*lui montrer juste pour creer du drama*"; //1ere reponse
    personnages[0].dialogues[13][2] = "*lui montrer pour qu'il se cassel*"; //2eme reponse
    personnages[0].dialogues[13][3] = "*lui montrer*"; //3eme reponse

    personnages[0].dialogues[14][0] = "Quoi ? C'etait quand on etais encore ensemble wesh"; //2e dialogue du garcon 0
    personnages[0].dialogues[14][1] = "Moi je dis bagarre"; //1ere reponse
    personnages[0].dialogues[14][2] = "Annnn ca m'aurais pas plu"; //2eme reponse
    personnages[0].dialogues[14][3] = "Bien fait"; //3eme reponse

    // KARIM 
    personnages[2].dialogues[9][0] = "Tu m'a l'air... de vouloir...me demander quelque chose"; //1er dialogue du garcon 1
    personnages[2].dialogues[9][1] = "Donne les codes de l'intranet je veux y publier une video"; //1ere reponse
    personnages[2].dialogues[9][2] = "Oue je voulais juste avoir les codes de l'intranet steup je vais mettre une video insane"; //2eme reponse
    personnages[2].dialogues[9][3] = "Je peux avoir les codes de l'intranet bi idhni Llah"; //3eme reponse

    personnages[2].dialogues[10][0] = "Oue mais c'est pour...quelle genre de video exactement ?"; //1er dialogue du garcon 1
    personnages[2].dialogues[10][1] = "*ne pas repondre puis lui montrer la video*"; //1ere reponse
    personnages[2].dialogues[10][2] = "*lui montrer la video en medisant sur la peste*"; //2eme reponse
    personnages[2].dialogues[10][3] = "*lui montrer la video*"; //3eme reponse

    personnages[2].dialogues[11][0] = "Tu ne devrais pas la publier c'est pas bien"; //1er dialogue du garcon 1
    personnages[2].dialogues[11][1] = "*se remettre en question et le faire quand meme*"; //1ere reponse
    personnages[2].dialogues[11][2] = "*l'ignorer et le faire quand meme*"; //2eme reponse
    personnages[2].dialogues[11][3] = "M'en fout *le faire quand meme*"; //3eme reponse

    // LA PESTE 
    personnages[4].dialogues[12][0] = "C'est toi qui a publie cette video je le sais"; //1er dialogue du garcon 1
    personnages[4].dialogues[12][1] = "Oue c'est moi wesh"; //1ere reponse
    personnages[4].dialogues[12][2] = "Je vois pas de quoi tu parles"; //2eme reponse
    personnages[4].dialogues[12][3] = "Bah oui logique"; //3eme reponse

    personnages[4].dialogues[13][0] = "Tu peux la supprimer s'il te plait"; //1er dialogue du garcon 1
    personnages[4].dialogues[13][1] = "Nan"; //1ere reponse
    personnages[4].dialogues[13][2] = "J'ai po envie"; //2eme reponse
    personnages[4].dialogues[13][3] = "Peut etre demain inchaAllah"; //3eme reponse

    personnages[4].dialogues[14][0] = "S'il te plait si ma mere vois ca je suis foutue et toi aussi d'ailleurs"; //1er dialogue du garcon 1
    personnages[4].dialogues[14][1] = "Oula non je suis pas a vos reunions de famille ein"; //1ere reponse
    personnages[4].dialogues[14][2] = "Non je crois pas non on partage pas le meme sang je crois"; //2eme reponse
    personnages[4].dialogues[14][3] = "Nan t'es toute seule dans ta caca la"; //3eme reponse

    // DESSEREE 
    personnages[3].dialogues[9][0] = "Viens la toi"; //1er dialogue du garcon 1
    personnages[3].dialogues[9][1] = "J'ai un prenom au cas ou"; //1ere reponse
    personnages[3].dialogues[9][2] = "Oue ?"; //2eme reponse
    personnages[3].dialogues[9][3] = "Ouiii madame hihi"; //3eme reponse

    personnages[3].dialogues[10][0] = "Tu va m'effacer cette video tout de suite"; //1er dialogue du garcon 1
    personnages[3].dialogues[10][1] = "Non j'ai pas trop envie"; //1ere reponse
    personnages[3].dialogues[10][2] = "Je ne pense pas que vous etes en droit de me donner des ordres"; //2eme reponse
    personnages[3].dialogues[10][3] = "Pourquoi je devrais faire ca et pourquoi c'est vous qui me le demandez"; //3eme reponse

    personnages[3].dialogues[11][0] = "Ecoute j'aime moyennement retrouver des videos sur internet de ma fille mise sans son consentement"; //1er dialogue du garcon 1
    personnages[3].dialogues[11][1] = "Oui je vais l'enlever de suite. Pardon...?"; //1ere reponse
    personnages[3].dialogues[11][2] = "Quoi ?? C'est votre fille ?"; //2eme reponse
    personnages[3].dialogues[11][3] = "C'est pas moi"; //3eme reponse 

    // =============== QUETE 2 ============================================================================== //22 interactions

    // MEYEEEEEER
    personnages[6].dialogues[0][0] = "Bonjour c'est pour s'inscrire au meilleur jeu de piste de l'annee ?"; //1er dialogue du garcon 1
    personnages[6].dialogues[0][1] = "Ouais ouais t'es bien renseigne toi"; //- 5
    personnages[6].dialogues[0][2] = "Oui"; // 0
    personnages[6].dialogues[0][3] = "Bonjour oui monsieur j'ai trop hate"; // 5

    personnages[6].dialogues[1][0] = "Vous avez trouve votre binome ? "; 
    personnages[6].dialogues[1][1] = "Non"; // 0
    personnages[6].dialogues[1][2] = "On est vraiment oblige de le faire en binome"; // -5
    personnages[6].dialogues[1][3] = "Pas vraiment"; // 5

    personnages[6].dialogues[2][0] = "Ne t'inquiete pas, vous etes encore beaucoup a etre seul je te conseille d'aller parler a d'autres etudiants"; 
    personnages[6].dialogues[2][1] = "Merci pour le conseil j'y vais"; // 5
    personnages[6].dialogues[2][2] = "Ok"; // 0
    personnages[6].dialogues[2][3] = "Et si j'ai pas envie"; // -5

    // CHAIMA
    personnages[5].dialogues[3][0] = "Salam 3aleykum ma go qu'est ce que tu racontes"; //1er dialogue du garcon 1
    personnages[5].dialogues[3][1] = "Rien je cherche quelqu'un pour le jeu de piste mais pas toi"; //- 5
    personnages[5].dialogues[3][2] = "Bah ecoute ca cherche quelqu'un pour le jeu la"; // 0
    personnages[5].dialogues[3][3] = "Wa 3aleykum salam bestie, je cherche un partenaire pour le jeu de piste"; // 5

    personnages[5].dialogues[4][0] = "Ah, moi ca va etre un peu chaud de toute facon"; 
    personnages[5].dialogues[4][1] = "Ah"; // 0
    personnages[5].dialogues[4][2] = "M'en fou"; // -5
    personnages[5].dialogues[4][3] = "Mais nooooooon pourquoi wesh"; // 5

    personnages[5].dialogues[5][0] = "Ah mais je me suis deja mise avec le M"; 
    personnages[5].dialogues[5][1] = "Ah tranquille profite"; // 5
    personnages[5].dialogues[5][2] = "Ok"; // 0
    personnages[5].dialogues[5][3] = "Sale pick me va"; // -5

    // LA PESTE
    personnages[4].dialogues[15][0] = "Olala encore toi"; 
    personnages[4].dialogues[15][1] = "C'est toi encore toi"; //-5
    personnages[4].dialogues[15][2] = "We"; // 0
    personnages[4].dialogues[15][3] = "Vivement que tu quittes cette fac"; // -10

    personnages[4].dialogues[16][0] = "Tu vas pas jouer au jeu de piste quand meme"; 
    personnages[4].dialogues[16][1] = "Sinon quoi"; // -5
    personnages[4].dialogues[16][2] = "Pourquoi ?"; // 0
    personnages[4].dialogues[16][3] = "Smehli la reine des neiges retourne dans ton chateau stp"; // -10

    personnages[4].dialogues[17][0] = "En tout cas moi je me met avec Oke"; 
    personnages[4].dialogues[17][1] = "On verra"; // -5
    personnages[4].dialogues[17][2] = "Ok"; // 0
    personnages[4].dialogues[17][3] = "Et lui il aussi il se met avec toi ouuuu ?"; // -10

    // OKE 
    personnages[0].dialogues[15][0] = "T'es toute seule pour le jeu de piste ?"; 
    personnages[0].dialogues[15][1] = "Pas tes affaires"; //-5
    personnages[0].dialogues[15][2] = "Pourquoi tu veux savoir"; //0
    personnages[0].dialogues[15][3] = "..."; //5

    personnages[0].dialogues[16][0] = "Tu veux qu'on se mette ensemble ?"; 
    personnages[0].dialogues[16][1] = "Je sais pas"; // 0
    personnages[0].dialogues[16][2] = "T'as pas une meuf toi ?"; // -5
    personnages[0].dialogues[16][3] = "La peste m'a dis que t'etais avec elle"; // 5

    personnages[0].dialogues[17][0] = "Mais on est meme plus ensemble"; //2e dialogue du garcon 0
    personnages[0].dialogues[17][1] = "Ah, elle te meritait pas tout de facon"; // 5
    personnages[0].dialogues[17][2] = "Ok oke"; // 0
    personnages[0].dialogues[17][3] = "hahahahhahahaaha"; // -5

    // ADAM
    personnages[1].dialogues[9][0] = "Salut, tu participes au jeu de l'AML ? "; //1er dialogue du garcon 1
    personnages[1].dialogues[9][1] = "Je te dis pas hihi"; // -5
    personnages[1].dialogues[9][2] = "Peut-etre"; //0
    personnages[1].dialogues[9][3] = "Je pense ouais"; //5

    personnages[1].dialogues[10][0] = "T'es toute seule ?"; //1er dialogue du garcon 1
    personnages[1].dialogues[10][1] = "..."; // 0
    personnages[1].dialogues[10][2] = "Meme si je le suis j'ai pas envie d'etre avec toi"; // -5
    personnages[1].dialogues[10][3] = "Ouais"; // 5

    personnages[1].dialogues[11][0] = "Si tu trouves personne avec qui te mettre je serais au 4 a la bu"; //1er dialogue du garcon 1
    personnages[1].dialogues[11][1] = "Merci"; // 5
    personnages[1].dialogues[11][2] = "Je vais voir"; // 0
    personnages[1].dialogues[11][3] = "M'attends pas"; // -5

    //KAAARIMMMM
    personnages[2].dialogues[12][0] = "Salam 3aleykum, euhhhh...ca va"; //1er dialogue du garcon 1
    personnages[2].dialogues[12][1] = "euuuuuuuh ouais (en l'imitant)"; //-5
    personnages[2].dialogues[12][2] = "Wsh bien et toi ?"; //0
    personnages[2].dialogues[12][3] = "Wa 3aleykum salam al hamdulilah merci"; //5

    personnages[2].dialogues[13][0] = "Tu vas...participer au jeu de l'AML ?"; //1er dialogue du garcon 1
    personnages[2].dialogues[13][1] = "Je sais pas"; //0
    personnages[2].dialogues[13][2] = "ca te regarde pas"; //-5
    personnages[2].dialogues[13][3] = "J'aimerais bien mais j'ai personne avec qui me mettre"; //5

    personnages[2].dialogues[14][0] = "Si tu as personne...je suis encore seul. Je t'attendrais ici"; 
    personnages[2].dialogues[14][1] = "Merci c'est gentil"; //5
    personnages[2].dialogues[14][2] = "Ok ok"; //0
    personnages[2].dialogues[14][3] = "Plutot mourir"; //-5

    // OKE 
    personnages[0].dialogues[18][0] = "Alors t'as trouve quelqu'un ?"; 
    personnages[0].dialogues[18][1] = "Toujours pas tes affaires"; //-5
    personnages[0].dialogues[18][2] = "Je me demande vraiment pourquoi tu veux savoir"; //0
    personnages[0].dialogues[18][3] = "Non"; //5

    personnages[0].dialogues[19][0] = "Tu veux toujours pas qu'on se mette ensemble ?"; 
    personnages[0].dialogues[19][1] = "Je sais pas"; // 0
    personnages[0].dialogues[19][2] = "Tu veux pas te mettre avec ton ex"; // -5
    personnages[0].dialogues[19][3] = "Je vais y reflechir.."; // 5

    personnages[0].dialogues[20][0] = "Toute maniere c'est juste pour gagner je t'attends ici si tu veux"; //2e dialogue du garcon 0
    personnages[0].dialogues[20][1] = "A tout de suite"; // 5
    personnages[0].dialogues[20][2] = "Ok oke"; // 0
    personnages[0].dialogues[20][3] = "Tu peux rever"; // -5

    //MEYER
    personnages[6].dialogues[3][0] = "Alors tu participes au meilleur jeu de l'annee"; //1er dialogue du garcon 1
    personnages[6].dialogues[3][1] = "L'abus y'a mieux"; //- 5
    personnages[6].dialogues[3][2] = "Je crois bien que oui"; // 0
    personnages[6].dialogues[3][3] = "We"; // 5

    personnages[6].dialogues[4][0] = "Et qui est ton binome ?"; 
    personnages[6].dialogues[4][1] = "Adam"; // 0
    personnages[6].dialogues[4][2] = "Oke"; // -5
    personnages[6].dialogues[4][3] = "Karim"; // 5

    personnages[6].dialogues[5][0] = "Bon, va chercher ton binome et reviens ici ce sera le point de depart"; 
    personnages[6].dialogues[5][1] = "A tout de suite"; // 5
    personnages[6].dialogues[5][2] = "Ok"; // 0
    personnages[6].dialogues[5][3] = "Ah ouais ca me donne des ordres et tout"; // -5

    // ================= choix ======================

    // ==== choix adam =====

    // ADAM
    personnages[1].dialogues[12][0] = "T'es venu quand meme hihi ?"; //1er dialogue du garcon 1
    personnages[1].dialogues[12][1] = "J'avais pas le choix en vrai"; // -5
    personnages[1].dialogues[12][2] = "Oui hihi"; //0
    personnages[1].dialogues[12][3] = "Et ouaaaaais"; //5

    personnages[1].dialogues[13][0] = "C'est gentil hihi"; //1er dialogue du garcon 1
    personnages[1].dialogues[13][1] = "Si tu le dis"; // 0
    personnages[1].dialogues[13][2] = "Pas voulu surtout"; // -5
    personnages[1].dialogues[13][3] = "Comme toi"; // 5

    personnages[1].dialogues[14][0] = "Bon on y va hihi"; //1er dialogue du garcon 1
    personnages[1].dialogues[14][1] = "Je te suis"; // 5
    personnages[1].dialogues[14][2] = "Ok hihi"; // 0
    personnages[1].dialogues[14][3] = "Redonne moi des ordres et on verra"; // -5

    // DESSEREE 
    personnages[3].dialogues[12][0] = "Eh miss"; //1er dialogue du garcon 1
    personnages[3].dialogues[12][1] = "J'ai toujours un prenom au cas ou"; // -5
    personnages[3].dialogues[12][2] = "We"; // 0
    personnages[3].dialogues[12][3] = "Oui madame ?"; // 5

    personnages[3].dialogues[13][0] = "T'as bientot fini ton projet"; //1er dialogue du garcon 1
    personnages[3].dialogues[13][1] = "Euh ..."; // 0
    personnages[3].dialogues[13][2] = "Ca regarde personne ca"; // -5
    personnages[3].dialogues[13][3] = "Bientot"; // 5

    personnages[3].dialogues[14][0] = "N'oublie pas que le rendu est pour le premier mai"; //1er dialogue du garcon 1
    personnages[3].dialogues[14][1] = "Je n'oublie pas"; // 5
    personnages[3].dialogues[14][2] = "Oui ok"; // 0
    personnages[3].dialogues[14][3] = "*partir*"; // -5

    //MEYER
    personnages[6].dialogues[6][0] = "Allez vous etes le dernier binome"; //1er dialogue du garcon 1
    personnages[6].dialogues[6][1] = "Orh c'est bon"; //- 5
    personnages[6].dialogues[6][2] = "Oui"; // 0
    personnages[6].dialogues[6][3] = "On se depeche"; // 5

    personnages[6].dialogues[7][0] = "Vous devez trouver 4 post it sur lesquels il y aura une enigme pour trouver l'objet a ramener"; 
    personnages[6].dialogues[7][1] = "Ok"; // 0
    personnages[6].dialogues[7][2] = "We"; // -5
    personnages[6].dialogues[7][3] = "Jusqu'ici c'est clair"; // 5

    personnages[6].dialogues[8][0] = "Le premier qui binome ramene l'objet a gagner allez"; 
    personnages[6].dialogues[8][1] = "Letsgoooo"; // 5
    personnages[6].dialogues[8][2] = "Ok"; // 0
    personnages[6].dialogues[8][3] = "En vrai nul un peu"; // -5

    // ADAM
    personnages[1].dialogues[15][0] = "T'as tout fait toute seule hihi ?"; //1er dialogue du garcon 1
    personnages[1].dialogues[15][1] = "En meme temps avec toi.. "; // -5
    personnages[1].dialogues[15][2] = "Oui hihi"; //0
    personnages[1].dialogues[15][3] = "hahaha oui"; //5

    personnages[1].dialogues[16][0] = "Je suis vraiment content que tu m'ai choisi t'es trop forte"; //1er dialogue du garcon 1
    personnages[1].dialogues[16][1] = "Merci la zone"; // 0
    personnages[1].dialogues[16][2] = "Pas comme toi"; // -5
    personnages[1].dialogues[16][3] = "Merci *genee*"; // 5

    personnages[1].dialogues[17][0] = "Du coup le lieu de rendez vous c'est au parc"; //1er dialogue du garcon 1
    personnages[1].dialogues[17][1] = "Je te suis"; // 5
    personnages[1].dialogues[17][2] = "Ok"; // 0
    personnages[1].dialogues[17][3] = "Ololo"; // -5
    
    // ===== choix oke ====

    // OKE 
    personnages[0].dialogues[21][0] = "Donc t'es revenu"; 
    personnages[0].dialogues[21][1] = "Commence pas je vais faire demi tour"; //-5
    personnages[0].dialogues[21][2] = "We"; //0
    personnages[0].dialogues[21][3] = "Ouais je voulais souler ta copine c'est tout"; //5

    personnages[0].dialogues[22][0] = "En vrai je pensais pas que t'allais le faire"; 
    personnages[0].dialogues[22][1] = "Si tu le dis"; // 0
    personnages[0].dialogues[22][2] = "En realite j'avais pas le choix"; // -5
    personnages[0].dialogues[22][3] = "J'avais envie d'etre tranquille avec toi pour une fois"; // 5

    personnages[0].dialogues[23][0] = "Allez maintenant faut gagner"; //2e dialogue du garcon 0
    personnages[0].dialogues[23][1] = "Letsgo"; // 5
    personnages[0].dialogues[23][2] = "Ok oke"; // 0
    personnages[0].dialogues[23][3] = "Avec toi...pas sur"; // -5

    // OKE 
    personnages[0].dialogues[24][0] = "Franchement t'as gere"; 
    personnages[0].dialogues[24][1] = "Je saaaais"; //-5
    personnages[0].dialogues[24][2] = "Haha"; //0
    personnages[0].dialogues[24][3] = "Meme toi franchement"; //5

    personnages[0].dialogues[25][0] = "Je te pensais pas aussi intelligente"; 
    personnages[0].dialogues[25][1] = "Si tu le dis"; // 0
    personnages[0].dialogues[25][2] = "Ah bon MOI je suis la premiere de la classe"; // -5
    personnages[0].dialogues[25][3] = "Je te retourne le compliment abruti"; // 5

    personnages[0].dialogues[26][0] = "Allez ils ont bouger au parc faut finir la bas"; //2e dialogue du garcon 0
    personnages[0].dialogues[26][1] = "Je te suis monsieur Oke"; // 5
    personnages[0].dialogues[26][2] = "Ok oke"; // 0
    personnages[0].dialogues[26][3] = "Allez"; // -5

    // ===== choix karim =====

    //KAAARIMMMM
    personnages[2].dialogues[15][0] = "Resalam 3aleykum...t'es revenu"; //1er dialogue du garcon 1
    personnages[2].dialogues[15][1] = "J'avais pas vraiment le choix"; //-5
    personnages[2].dialogues[15][2] = "Oui"; //0
    personnages[2].dialogues[15][3] = "Wa 3aleykum salam haha oui"; //5

    personnages[2].dialogues[16][0] = "Honnetement j'ai participe en esperant que tu me choisisses"; //1er dialogue du garcon 1
    personnages[2].dialogues[16][1] = "Ah ouais ?"; //0
    personnages[2].dialogues[16][2] = "Ah we chaud"; //-5
    personnages[2].dialogues[16][3] = "Annnnw c'est trop mimi"; //5

    personnages[2].dialogues[17][0] = "Bon..on y va ?"; 
    personnages[2].dialogues[17][1] = "Bien sur je te suis"; //5
    personnages[2].dialogues[17][2] = "Oui"; //0
    personnages[2].dialogues[17][3] = "*rien dire wewe*"; //-5

    //KAAARIMMMM
    personnages[2].dialogues[18][0] = "Ma sha Allah t'as tout reussi"; //1er dialogue du garcon 1
    personnages[2].dialogues[18][1] = "Bah we logique"; //-5
    personnages[2].dialogues[18][2] = "Oui"; //0
    personnages[2].dialogues[18][3] = "Hihi merci toi aussi franchement tu m'as aide"; //5

    personnages[2].dialogues[19][0] = "Allah y berek t'es super intelligente je l'avais vu"; //1er dialogue du garcon 1
    personnages[2].dialogues[19][1] = "Ah ouais ?"; //0
    personnages[2].dialogues[19][2] = "..."; //-5
    personnages[2].dialogues[19][3] = "*sourire toute genee*"; //5

    personnages[2].dialogues[20][0] = "Euh..je crois que c'est rdv au parc ?"; 
    personnages[2].dialogues[20][1] = "On y va en mode gagnant"; //5
    personnages[2].dialogues[20][2] = "Ok"; //0
    personnages[2].dialogues[20][3] = "*le suivre*"; //-5

    //MEYER
    personnages[6].dialogues[9][0] = "Vous avez gagne !!!"; //1er dialogue du garcon 1
    personnages[6].dialogues[9][1] = "Evidemment"; //- 5
    personnages[6].dialogues[9][2] = "Oui"; // 0
    personnages[6].dialogues[9][3] = "Bien sur"; // 5

    personnages[6].dialogues[10][0] = "Alors meilleur jeu de la fac ?"; 
    personnages[6].dialogues[10][1] = "..."; // 0
    personnages[6].dialogues[10][2] = "Sah non"; // -5
    personnages[6].dialogues[10][3] = "Franchement ca va c'etait cool"; // 5

    personnages[6].dialogues[11][0] = "Allez t'as un projet a rendre le 1er mai"; 
    personnages[6].dialogues[11][1] = "J'y vais monsieur"; // 5
    personnages[6].dialogues[11][2] = "Oui"; // 0
    personnages[6].dialogues[11][3] = "Jmen fou"; // -5

    // LA PESTE
    personnages[4].dialogues[18][0] = "T'as gagne juste parce que j'avais pas envie"; 
    personnages[4].dialogues[18][1] = "J'allais te le dire"; //-5
    personnages[4].dialogues[18][2] = "Si tu veux"; // 0
    personnages[4].dialogues[18][3] = "Ou alors parce que tu sais pas resoudre une vieille enigme"; // -10

    personnages[4].dialogues[19][0] = "Tout de facon je m'en fiche c'est un vieux jeu"; 
    personnages[4].dialogues[19][1] = "Tout ca parce que t'as perdu"; // -5
    personnages[4].dialogues[19][2] = "Si tu le dis"; // 0
    personnages[4].dialogues[19][3] = "Hahahahhaaa t'es trop nulle"; // -10

    personnages[4].dialogues[20][0] = "Allez barre toi"; 
    personnages[4].dialogues[20][1] = "Parle mieux"; // -5
    personnages[4].dialogues[20][2] = "* partir *"; // 0
    personnages[4].dialogues[20][3] = "Behhhh t'as trop la rage"; // -10

}

Personnages::Personnages(){

    personnages[0]=Personne( "Castiel GraineDeCafeMauvaisGarcon", "Castiel est le bad boy de la fac. \nIl aime faire lever sa moto en Y devant le batiment Themis et cracher par terre. \n\n" );

    personnages[1]=Personne("Nathaniel LeFayot","Nathaniel est le fayot de la promo. \nIl aime rapeller au prof qu'il y avait un devoir à rendre et t'as souvent mansplain les cours quand tu as demande de l'aide. \n\n");
    
    personnages[2]=Personne("Karim Akhy"," Karim ou akhy Karim est un garcon doux et attentionne. \nIl ne t'as jamais regarde dans les yeux mashaAllah et t'as deja aide dans certaines matière avec humour et gentillesse. \n\n");

    personnages[3]=Personne("Elodie Desseree","Elodie Desseree t'accompagne depuis l'an dernier avec les cours de LIFAP1. \nToujours très bien habillee, elle est très gentille et adore mettre de bonnes notes aux projets de ses elèves ^^ \n\n ");

    personnages[4]=Personne("Peste","La peste est une grosse peste. \nElle te met toujours des bâtons dans les roues pour gerer tes crushs. \n\n ");

    personnages[5]=Personne("Chaïma OukhtyFuzeTea","Chaima est une fille douce et gentille. \nElle est toujours là pour toi et est une personne sur qui tu peux compter au sein du campus. \n\n");
       
    personnages[6]=Personne("Alexandre Meyer","Bien qu'il t'ai traumatise l'an dernier avec Grapic, \nAlexandre Meyer est un prof très sympa qui a toujours de bon conseils. \n\n");
    

}

