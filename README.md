# Laboratorinis darbas
Darbą sudaro 6 release'ai: v0.1, v0.2, v0.3, v0.4, v0.5, v1.0;

## v0.1
Šioje versijoje yra realizuota programa, kuri leidžia vartotojui įvesti studento vardą ir pavardę, namų darbų pažymius ir egzamino įvertinimą. Baigus duomenų įvedimą programa apskaičiuoja studento galutinį balą, naudojant formulę: 

                                           0.4 * namų darbų vidurkis + 0.6 * egzaminas. 

Studento vardas ir pavardė bei galutinis įvertinimas pateikiami ekrane. Galutinis įvertinimas išvedamas dviem būdais: galutinis, kur naudojamas vidurkis ir galutinis, kur naudojama mediana. Programa paruošta taip, kad vartotojas įvedimo metu pasirenka kiek įves namų darbų pažymių. Ši dalis realizuota naudojant ir C masyvą, ir std::vector tipo konteinerį. Galiausiai programa papildyta taip, kad tiek namų darbų pažymiai, tiek egzamino pažymys gali būti sugeneruotas kompiuterio.

#### Naudojimo instrukcija:
1 žingsnis: vartotojas įveda studentų skaičių, kurių duomenis pildys programoje.

2 žingsnis: vartotojas įveda vieno studento vardą ir pavardę.

3 žingsnis: vartotojas pasirenka ar pažymiai bus generuojami, ar įvedami ranka.

Vartotojui pasirinkus, jog visus pažymius suves ranka, paprašoma įvesti egzamino įvertinimą ir tada namų darbų įvertinimus, kuriuos reikia vesti atskiriant tarpeliu ir baigus įvesti spausti 'enter'.

Vartotojui pasirinkus, jog visus pažymius sugeneruojas kompiuteris, reikia kiekvieną kartą patvirtinti, jog nori ar nenori generuoti daugiau pažymių, kol bus sugeneruotas vartotojo norimas pažymių kiekis.

Baigus pildyti studento duomenis, taip pat elgiamasi su kitų studentų duomenų pildymu. Baigus vykdyti programą į ekraną išvedami rezultatai.

[v0.1] (https://github.com/ekondrataite/Laboratorinis/releases/tag/v0.1)

## v0.2
Ši versija yra pirmosios versijos papildymas. Dabar galima pasirinkti ar duomenis norima įvesti ar nuskaityti iš failo. Nuskaičius duomenis iš failo įvykdomas toks pat išvedimas į ekraną, kur pateikiamas studento vardas, pavardė ir galutinis balas vidurkio bei medianos pavidalu. Programa taip pat papildyta, jog galima pasirinkti kaip surūšiuoti studentų sąrašą: pagal vardus arba pagal pavardes.

#### Naudojimo instrukcija:
1 žingsnis: Vartotojas pasirenka ar duomenis įrašys ranka, ar nuskaitys iš failo.

Jei vartotojas pasirenka duomenis suvesti ranka žr. v0.1 naudojimo instrukciją ir papildomai suvestų duomenų gale pasirinkti kaip rušiuoti duomenis.

Jei vartotojas pasirenka duomenis nuskaityti iš failo, jo paprašoma įvesti failo, iš kurio bus nuskaitomi duomenis, pavadinimą. Programai atlikus nuskaitymą ir galutinio balo skaičiavimą vartotojo paklausiama kaip jis nori surūšiuoti studentų sąrašą.

[v0.2] (https://github.com/ekondrataite/Laboratorinis/releases/tag/v0.2)

## v0.3
Šioje versijoje atliekamas antrosios versijos reorganizavimas. Funkcijos perkeliamos į antraštinius failus. Panaudojamas išimčių valdymas.

#### Naudojimo instrukcija:
Naudojimo instrukcija sutampa su v0.3 versijos naudojimo instrukcija.

[v0.3] (https://github.com/ekondrataite/Laboratorinis/releases/tag/v0.3)

## v0.4
Šioje versijoje yra programa, kuri generuoja studentų failus. Studentų vardai ir pavardės yra šabloniniai (Vardenis0 Pavardenis0, ...), o studentų pažymiai generuojami kompiuterio. Sugeneravus studentų failus, programa papildyta, kad failus sugrupuotų į dvi grupes: "kietiakai" ir "vargsiukai". Skaidymo strategijas: sukurti du nauji konteineriai 'kietiakai' ir 'vargsiukai', duomenis sugrupavus, studentas lieka bendrame konteineryje ir atsiranda dar kuriame nors iš išvardytųjų, priklausomai, koks studento galutinis balas. Šios dvi grupės įrašomos į atskirus failus. Programoje įgyvendinami laiko matavimai. Vykdant programą matauojama ir į ekraną išvedama kiek užtruko sugeneruoti ir į failą įrašyti duomenis, kiek užtruko nuskaityti duomenis iš failo ir sugrupuoti į dvi kategorijas bei kiek užtruko sugrupuotus duomenis išvesti į naujus failus.

#### Naudojimo instrukcija:
1 žingsnis: vartotojas įveda kokį kiekį studentų nori sugeneruoti.

2 žingsnis: vartotojas įveda kiek pažymių kiekvienam studentui turi būti sugeneruojama.

3 žingsnis: vartotojas įveda failo pavadinimą, į kurį bus irašomas studentų sąrašas.

4 žingsnis: vartotojo klausiama ar nori studentų sąrašą sugrupuoti į dvi kategorijas.

5 žingsnis: vartotojo paprašoma pakartoti failo, kurį nori sugrupuoti pavadinimą.

Programa atlieka veiksmus ir išveda grupes į du skirtingus failus.

[v0.4] (https://github.com/ekondrataite/Laboratorinis/releases/tag/v0.4)

## v0.5
Šioje programos versijoje atliekami laiko testavimai su 'list' ir 'vector' konteineriais. Testavimui pasitelkiami failai sugeneruoti v0.4 versijoje: studentai1000.txt, studentai10000.txt, studentai100000.txt, studentai1000000.txt, studentai10000000.txt. Testavimas taikomas duomenų iš failo nuskaitymui ir grupavimui į dvi grupes. Gauti rezultatai parodė, kad naudojant 'list' tipo konteinerį programa veikia greičiau nei pasitelkus 'vector' konteinerį, tačiau laiko skirtumas nėra didelis.

[v0.5] (https://github.com/ekondrataite/Laboratorinis/releases/tag/v0.5)

## v1.0
Šioje versijoje programoje įgyvendinama reikalavimuose numatyta 2-oji skirstymo į grupes strategija, nes 1-oji buvo įgyvendinta jau v0.5 versijoje. Strategija: studentų skaidymui į dvi kategorijas pasitelkiamas vienas naujas konteineris 'vargsiukai'; jei studentas yra vargsiukas, jis įkeliamas į naująjį konteinerį ir ištrinamas iš senojo, tokiu būdu senasis konteineris priklausys 'kietiakai' kategorijos studentams. Atliekami laiko matavimai 'vector' ir 'list' tipo konteineriams, patikrinti, kuris būdas laiko atžvilgiu yra efektyvesnis. Rezultatai parodo, kad 2-ojoje strategijoje programa veikia greičiau naudojant 'list' tipo konteinerį.

#### Naudojimo instrukcija:
1 žingsnis: Vartotojas pasirenka konteinerio tipą, kurį nori naudoti studentų sąrašo grupavimui į dvi grupes.

2 žingsnis: Vartotojas turi įvesti failo pavadinimą, kurį grupuos.

Programa atlieka veiksmus ir išveda į ekraną rezultatą: laiką, kiek programa užtruko suskirstyti studentus į dvi kategorijas.
