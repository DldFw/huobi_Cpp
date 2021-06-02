#include <client/accountClient.h>

using namespace std;

int main() {
    AccountClient accountClient{APIKEY, SECRETKEY};
    vector<Account> accounts = accountClient.getAccounts();
    cout << accounts[0].type << endl;

    vector<Balance> balanceVec = accountClient.getBalance(3504844);
    cout << balanceVec[0].type << endl;

   /* AccountHistoryRequest accountHistoryRequest{3504844, "usdt"};
    accountHistoryRequest.transactTypes = "trade";
    accountHistoryRequest.size = 10;
    vector<AccountHistory> accountHistory = accountClient.getHistory(accountHistoryRequest);
    cout << accountHistory[0].currency << endl;*/

    /*AccountLedgerRequest accountLedgerRequest{3504844, "usdt"};
    accountClient.getLedger(accountLedgerRequest);

    FuturesTransferRequest futuresTransferRequest{"usdt", "0.2", "futures-to-pro"};
    cout << accountClient.futuresTransfer(futuresTransferRequest) << endl;*/

   /* vector<AccountAndBalance> accountAndBalanceVec = accountClient.getSubuidAccount(3504844);
    cout << accountAndBalanceVec[0].symbol << endl;*/
    AssetValuationRequest request;
    request.accountType = "spot";
    request.valuationCurrency ="cny";
    AssetValuation assetValuation = accountClient.getAssetValuation(request);
    cout << "i have " << assetValuation.balance << " in " << assetValuation.timestamp << endl;
    return 0;
}

