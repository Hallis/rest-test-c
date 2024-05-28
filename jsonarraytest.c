#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <json-c/json_util.h>

int main()
{
    char *myArr = "{\"person\":{\"identitet\":165562503630,\"aviseringsnamn\":\"Schenker Och Bussgods Sveg\",\"bokslutsdatum\":\"2012-06-30\",\"handlaggningskod\":\"0141F6013\",\"skuldutredning\":false,\"kommunkod\":\"1480\",\"identitetsbeteckning\":[{\"identitet\":165562503630,\"typ\":\"ONR\",\"datumFROM\":\"1997-01-01\"}],\"kontaktuppgiftPostadress\":[{\"datumFROM\":\"1997-01-01\",\"typPostadress\":\"Hemadress för ej folkbokförd\",\"kodTypPostadress\":2,\"utdelningsadress\":[\"\",\"Parkgatan 17\"],\"postnummer\":84233,\"postort\":\"SVEG\"}],\"juridiskPerson\":{\"juridiskForm\":\"OSKIFTADE DÖDSBON\",\"kodJuridiskForm\":91,\"namn\":\"Schenker Och Bussgods Sveg\",\"rakenskapsarFROM\":\"2023-07-01\",\"rakenskapsarTOM\":\"2024-06-30\",\"registreringsdatum\":\"1997-01-01\"}}}";

    struct json_object *jobj, *personobj = NULL, *kontaktuppgifter = NULL, *avisnamn = NULL, *kontakt = NULL;
    struct json_object *adresser = NULL;
    struct json_object *tmp;
    struct json_object *adress1 = NULL;
    struct json_object *adress2 = NULL;

    jobj = json_tokener_parse(myArr);

    json_object_object_get_ex(jobj, "person", &personobj);

    json_object_object_get_ex(personobj, "aviseringsnamn", &avisnamn);
    json_object_object_get_ex(personobj, "kontaktuppgiftPostadress", &kontaktuppgifter);

    kontakt = json_object_array_get_idx(kontaktuppgifter, 0);
    json_object_object_get_ex(kontakt, "utdelningsadress", &adresser);

    if (adresser != NULL)
    {
        adress1 = json_object_array_get_idx(adresser, 0);
        adress2 = json_object_array_get_idx(adresser, 1);
    }

    // aviseringsnamn
    printf("avisnamn: %s\n", json_object_get_string(avisnamn));

    // Adresser
    if (adress1 != NULL)
        printf("adress 1: %s\n", json_object_get_string(adress1));
    if (adress2 != NULL)
        printf("adress 2: %s\n", json_object_get_string(adress2));

    // postnummer
    json_object_object_get_ex(kontakt, "postnummer", &tmp);
    printf("postnummer: %d\n", json_object_get_int(tmp));
    // postort
    json_object_object_get_ex(kontakt, "postort", &tmp);
    printf("postort: %s\n", json_object_get_string(tmp));

    return 0;
}
