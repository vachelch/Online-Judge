"""
# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution:
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        dic = {}
        for i in range(len(employees)):
            dic[employees[i].id] = i

        def get_imp(employee):
            val = employee.importance
            for id_ in employee.subordinates:
                val += get_imp(employees[dic[id_]])
            return val

        return get_imp(employees[dic[id]])