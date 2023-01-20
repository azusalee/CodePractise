import UIKit


class Solution {
    func findingUsersActiveMinutes(_ logs: [[Int]], _ k: Int) -> [Int] {
        var result: [Int] = []
        for i in 0..<k {
            result.append(0)
        }
        
        var dict: [Int: Set<Int>] = [:]
        
        for log in logs {
            if (dict[log[0]] == nil) {
                dict[log[0]] = []
            }
            dict[log[0]]!.insert(log[1])
        }
        
        for (_, times) in dict {
            result[times.count-1] += 1
        }
        
        return result
    }
}

let logs = [[0,5],[1,2],[0,2],[0,5],[1,3]]

let result = Solution().findingUsersActiveMinutes(logs, 5)
