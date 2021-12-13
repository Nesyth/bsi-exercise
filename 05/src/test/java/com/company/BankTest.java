package com.company;

import org.junit.jupiter.api.*;

import static com.company.Main.*;
import static java.lang.Integer.parseInt;
import static org.junit.jupiter.api.Assertions.*;

class BankTest {
    @BeforeEach
    void BeforeEach() {
        createDatabase(fileName);
        createTable(fileName);
    }

    @Test
    @DisplayName("Check if user creation method works")
    void checkIfCardNumberAndCardPinExist() {
        InsertApp insertApp = new InsertApp(fileName);
        SelectApp selectApp = new SelectApp(fileName);
        Card account = new Card();

        // Create new account
        insertApp.insert(
                Long.parseLong(account.getCardNumber()),
                parseInt(account.getPin()),
                account.getBalance()
        );

        boolean isNumber = selectApp.checkNumber(Long.parseLong(account.getCardNumber()));
        boolean isPin = selectApp.checkPin(Long.parseLong(account.getPin()));

        assertTrue(isNumber);
        assertTrue(isPin);
    }

    @Test
    @DisplayName("Check if choosing +1 values from DB works")
    void checkIfRandomCardNumberAndCardPinExist() {
        InsertApp insertApp = new InsertApp(fileName);
        SelectApp selectApp = new SelectApp(fileName);
        Card account = new Card();

        // Create new account
        insertApp.insert(
                Long.parseLong(account.getCardNumber()),
                parseInt(account.getPin()),
                account.getBalance()
        );

        boolean isNumberPlusOne = selectApp.checkNumber(Long.parseLong(account.getCardNumber() + 1));
        boolean isPinPlusOne = selectApp.checkPin(Long.parseLong(account.getPin() + 1));

        assertFalse(isNumberPlusOne);
        assertFalse(isPinPlusOne);
    }

    @Test
    @DisplayName("Check if removing the account from DB works")
    void checkIfCanDeleteCard() {
        InsertApp insertApp = new InsertApp(fileName);
        SelectApp selectApp = new SelectApp(fileName);
        DeleteApp deleteApp = new DeleteApp(fileName);
        Card account = new Card();

        // Create new account
        insertApp.insert(
                Long.parseLong(account.getCardNumber()),
                parseInt(account.getPin()),
                account.getBalance()
        );

        // Check if the account got created, expected: exists() == true
        assertTrue(selectApp.checkNumber(Long.parseLong(account.getCardNumber())));

        // Remove the account
        deleteApp.deleteRow(Long.parseLong(account.getCardNumber()));

        // Check if the account got removed, expected: exists() == false
        assertFalse(selectApp.checkNumber(Long.parseLong(account.getCardNumber())));
    }

    @Test
    @DisplayName("Check if updating balance in DB works")
    void checkIfCanUpdateBalance() {
        InsertApp insertApp = new InsertApp(fileName);
        SelectApp selectApp = new SelectApp(fileName);
        UpdateApp updateApp = new UpdateApp(fileName);
        Card account = new Card();

        // Create new account
        insertApp.insert(
                Long.parseLong(account.getCardNumber()),
                parseInt(account.getPin()),
                account.getBalance()
        );

        // Update balance from 0 to 10000
        updateApp.addIncome(
                Long.parseLong(account.getCardNumber()),
                10000
        );

        assertEquals(10000, selectApp.returnBalance(Long.parseLong(account.getCardNumber())));
        // assertEquals(10000, account.getBalance());
    }
}
