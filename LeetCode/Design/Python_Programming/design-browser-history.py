#/*
# * 1472. Design Browser History
# *
# * https://leetcode.com/problems/design-browser-history/
# * 
# * Runtime: 246 ms (81.71% Better)
# * Memory Usage: 16.7 MB (31.33 Better than)
# */

class BrowserHistory:

    def __init__(self, homepage: str):
        self.lifo = list()
        self.lifo.append(homepage)
        self.location = 0

    def visit(self, url: str) -> None:
      if (self.location == (len(self.lifo)-1)):
        self.lifo.append(url)
        self.location += 1
      else:
        diff = len(self.lifo)-1 - self.location
        for i in range(diff):
          self.lifo.pop()
        self.lifo.append(url)
        self.location += 1
        
    def back(self, steps: int) -> str:
      if (steps > self.location):
        self.location = 0
      else:
        self.location -= steps
      return self.lifo[self.location]

    def forward(self, steps: int) -> str:
      if (steps > (len(self.lifo)-1-self.location)):
        self.location = len(self.lifo)-1
      else:
        self.location += steps
      return self.lifo[self.location]
        


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
