# matrix-multiplication
Matrix multiplication

## Run
```
cmake -S. -Bbuild
cd build
cmake --build .
ctest
```

## Implementace
Implementace pro jedno vlákno je triviální. 
Vícevláknová implementace rozdělí problem na menší problémy ( vynásobení jediného řádku s jediným sloupcem). Podproblém je předán do fronty úkolů, ze kterých si vlákna z thread poolu vybírají dokud neni fronta prázdná.

Množství vláken v thread poolu lze předat jako parametr nebo použít defaultně nastavených 8 vláken.

Soubor ve kterém je matice uložena musí mít následující format:
1.řádek pocet_radku mezera pocet_sloupcu
2.řádek dále nasledují prvky matice oddělené mezerou.

Náhodné matice lze vytvořit pomocí přepínače -generate-random-matrix left_row left_col right_row right_col -left_matrix path_to_left_matrix -right_matrix path_to_right_matrix
Poté bude vygenerována matice s příslušným počtem řádků a sloupců a uložena na zadané cestě.

Přepínače -left_matrix a -right_matrix slouží k předání cesty k daným maticím a jsou povinné.
Přepínače -result_matrix slouží k předání cesty kam se ma vysledná matice vyexportovat. Jedná se o volitelný parameter, pokud nebude zapsán vypíše se výsledek do konzole.
Přepínač -multithread je volitelný parameter, který povolí vícevláknové řešení. Volitelný parameter za číslo za přepínačem, který lze změnit počet vláken.
