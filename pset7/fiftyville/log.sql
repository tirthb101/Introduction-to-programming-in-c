SELECT description FROM crime_scene_reports WHERE year = 2020 AND day = 28 AND month = 7 AND street = "Chamberlin Street";
--Theft at 10:15 am

SELECT transcript FROM interviews WHERE year = 2020 AND day = 28 AND month = 7;
-- TRANSCRIPT 1:Drove away within 10 minites
-- TRANSCRIPT 2:widhray money on morning from fifer street atm
-- TRANSCRIPT 3:While leaving made call less than one minite and asked to buy ticket



--The following huge quary finds people who come under requirements for all 3 transcript
SELECT name
FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020 AND day = 28 AND month = 7 AND hour = 10 AND minute > 15 AND minute < 25

INTERSECT

SELECT name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON  bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2020 AND day = 28 AND month = 7

INTERSECT

SELECT name FROM people WHERE phone_number IN
(SELECT caller
FROM phone_calls
WHERE year = 2020 AND day = 28 AND month = 7 AND duration <= 60);



-- suspects: Ernest, Russell
SELECT origin_airport_id, destination_airport_id
FROM flights WHERE id IN(
    SELECT flight_id
    FROM passengers
    WHERE passport_number IN(
        SELECT passport_number
        FROM people
        WHERE name ="Ernest"));
--Ernest's OUTPUT: 8 | 4


SELECT origin_airport_id, destination_airport_id
FROM flights WHERE id IN(
    SELECT flight_id
    FROM passengers
    WHERE passport_number IN(
        SELECT passport_number
        FROM people
        WHERE name ="Ernest"));
--Russell's output: 8 | 6
                  --7 | 8
                  --8 | 5


SELECT full_name, id FROM airports WHERE id = 8;
--full_name | id
--Fiftyville Regional Airport | 8
--Ernest is the theif as he went out of fiftyville and didn't returned while russll did returnback



-- NOW who was the accomplice of Ernest

SELECT name
FROM people
WHERE phone_number IN(
    SELECT receiver
    FROM phone_calls
    WHERE caller IN (
        SELECT phone_number
        FROM people
        WHERE name = "Ernest")
    AND year = 2020 AND day = 28 AND month = 7 AND duration < 60);

--OUTPUT: Berthold


SELECT full_name, id FROM airports WHERE id = 4;
--AIRPORT no.4 hethrow is in london so theif went to london

