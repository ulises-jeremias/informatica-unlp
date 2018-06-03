PROCEDURE puente_unidireccional IS

    TASK TYPE Auto;
    TASK TYPE Camioneta;
    TASK TYPE Camion;

    TASK Puente IS
        BEGIN
            ENTRY auto_pide_puente;
            ENTRY auto_sale;
            ENTRY camioneta_pide_puente;
            ENTRY camioneta_sale;
            ENTRY camion_pide_puente;
            ENTRY camion_sale;
        END Puente

    TASK Puente BODY IS
        cantVehiculos: Integer := 0;

        BEGIN
            LOOP
                  SELECT WHEN (cantVehiculos + 6 <= 6) =>
                      ACCEPT camion_pide_puente DO
                          cantVehiculos += 6;
                      END camion_pide_puente;
                  OR WHEN (cantVehiculos + 3 <= 6) =>
                      ACCEPT camioneta_pide_puente DO
                          cantVehiculos += 3;
                      END camioneta_pide_puente;
                  OR WHEN (cantVehiculos + 2 <= 6) =>
                      ACCEPT auto_pide_puente DO
                          cantVehiculos += 2;
                      END auto_pide_puente;
                  OR
                      ACCEPT auto_sale;
                      cantVehiculos -= 2;
                  OR
                      ACCEPT camioneta_sale;
                      cantVehiculos -= 3;
                  OR
                      ACCEPT camion_sale;
                      cantVehiculos -= 6;
                  END LOOP;
        END Puente

    TASK BODY Auto IS
        BEGIN
            Puente.auto_pide_puente;
            pasar();
            Puente.auto_sale;
        END Auto

    TASK BODY Camioneta IS
        BEGIN
            Puente.camioneta_pide_puente;
            pasar();
            Puente.camioneta_sale;
        END Camioneta

    TASK BODY Camion IS
        BEGIN
            Puente.camion_pide_puente;
            pasar();
            Puente.camion_sale;
        END Camion

BEGIN
  null;
END puente_unidireccional;
