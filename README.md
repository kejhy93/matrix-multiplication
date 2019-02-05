# matrix-multiplication
Matrix multiplication

## Implementace
Implementace pro jedno vlakno je trivialni. 
Vicevlaknova implementaci rozdeli problem na mensi problemy ( vynasobeni jedineho radku s jednim sloupcem). Podproblem je predan do fronty ukolu, ze kterych si vlakna z thread poolu vybiraji dokud neni fronta prazdna.

Mnozstvi vlaken v thread poolu lze predat jako parametr nebo pouzit defaulte 8 vlaken.

Soubor ve kterem je matice ulozena musi mit nasledujici format:
1.radek pocet_radku mezera pocet_sloupcu
2.radek dale nasleduji prvky matice oddelene mezerou.

Nahodne matice lze vtvorit pomoci prepinace -generate-random-matrix left_row left_col right_row right_col -left_matrix path_to_left_matrix -right_matrix path_to_right_matrix
Pote bude vygenerovana matice s prislusnym poctem radku a sloupcu a ulozena na zadane ceste.

Prepinace -left_matrix a -right_matrix slouzi k predani cesty k danym maticim a jsou povinne.
Prepinace -result_matrix slouzi k predani cesty kam se ma vysledna matice vyexportovat. Jedna se o volitelny parameter, pokud nebude zapsan vypise se vysledek do konzole.
Prepinac -multithread je volitelny parameter, ktery povoli vicevlaknove reseni. Volitelny parameter za cislo za prepinacem, ktery lze zmenit pocet vlaken.
