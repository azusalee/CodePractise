import Foundation

class Solution {
    func accountsMerge(_ accounts: [[String]]) -> [[String]] {
        
        var emailDict: [String: Int] = [:]
        var accountEmails: [Int: [String]] = [:]
        
        for i in 0..<accounts.count {
            let account = accounts[i]
            
            var firstSameAccountID: Int?
            for j in 1..<account.count {
                let email = account[j]
                
                if let accountId = emailDict[email] {
                    if accountId == i {
                        continue
                    }
                    if firstSameAccountID == nil {
                        firstSameAccountID = accountId
                        if let otherEmails = accountEmails[i] {
                            for otherEmail in otherEmails {
                                accountEmails[firstSameAccountID!]?.append(otherEmail)
                                emailDict[otherEmail] = firstSameAccountID!
                            }
                            accountEmails.removeValue(forKey: i)
                        }
                    } else if firstSameAccountID != accountId {
                        // 其他相同账号
                        if let otherEmails = accountEmails[accountId] {
                            for otherEmail in otherEmails {
                                accountEmails[firstSameAccountID!]?.append(otherEmail)
                                emailDict[otherEmail] = firstSameAccountID!
                            }
                            accountEmails.removeValue(forKey: accountId)
                        }
                    }
                } else {
                    // 以数组下标当做是账户的唯一标识
                    if let firstSameAccountID = firstSameAccountID {
                        emailDict[email] = firstSameAccountID
                        accountEmails[firstSameAccountID]?.append(email)
                    } else {
                        emailDict[email] = i
                        if accountEmails[i] == nil {
                            accountEmails[i] = []
                        }
                        accountEmails[i]?.append(email)
                    }
                }
            }
        }
        
        var results: [[String]] = []
        for (accountId, emails) in accountEmails {
            results.append([accounts[accountId][0]]+emails.sorted())
        }
        return results
    }
}


