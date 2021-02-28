# The Phoenix Project

I've been reading _The Pheonix Project_ as part of a work book club at Nasdaq. These summaries will be used during the discussion to catch up individuals who didn't get a change to read or for me to review.

## Summaries

### Chapter 7 - Friday, September 5

The chapter opens with a call from Steve's secretary, Stacy, informing Bill that Steve would like him to meet a potential board member **Erik Reid**. Erik is apparently a guru of sorts, and Steve and the chairman of the board, Bob Strauss, both want him to get on board; so they convince Bill to meet with him before he leaves town.

Immediately, Bill gets off to a bad impression by mistaking Erik with a doughnut delivery person, mostly due to the Erik's enkempt appearance and wrinkled clothes. As Bill and Erik start talking, Erik lists of several names of people in the company, seemingly purposefully mispronouncing _everyone's_ names (this is an important detail later as Bill will note). But more alarming, after hearing Bill's predicament, Erik claims that Bill doesn't know the definition of "work". He posits that completing the Phoenix project for Steve is only one form of work, but that there are three other forms out there.

With a simple "Grab your stuff. We're going for a ride," Bill and Erik are on their way to one of Parts Unlimited's manufacturing plants. Erik is able to get them access because he recalls the name of the security guard (see, told you that mattered [but also really doesn't matter]). We also find out briefly that he is called _Dr. Reid_ by some.

Inside, Bill and Erik head up to the catwalks above the main plant, where they observe the different parts of the plant. Eric mentions that the plant received updates in the form of three management movements.

1. Theory of Constraints
2. Lean Production (Toyota Production System)
3. Total Quality management

Each of the three agree that pending "Work in Progress" (WIP) is the "silent killer" and that to properly function, you must control job and material release.

Erik then leads into a discussion about bottlenecks; at the manufacturing plant, there used to be one guy at a desk (Mark) who would send incoming work to the other areas of the factory. However, he didn't consider the work those departments were currently engaged in before sending the task. In an attempt to keep his department active, he continued to send work down to blocked up bottlenecks. The important part of fixing the problem was identifying the bottleneck; if you don't do that first, then any changes you make will have minimal impact. Changes before the bottleneck will just lead to more pile up at the bottle neck, while changes after the bottleneck will be wasted and see no additional work.

As they wrap up, Erik asserts that until Bill learns the definition of work, Erik's lessons will go right over his head and he won't be able to see the bigger picture. Bill needs to find the "Mark" in his department; once he does, he can figure out how to control the release of work into IT and ensure that the most constrained resources are doing only the work that serves the entire system. Once he's done that, Bill can begin to understand the three ways

1. The First Way
  - "...helps us undnerstand how to create fast flow of work as it moves from Development into IT Operations"
2. The Seconds Way
  - "...shows us how to shorten and amplify feedback loops, so we can fix quality at the source and avoid rework."
3. The Third Way
  - "...shows us how to create a culture that simulteneously fosters experimentation, learning from failure, and understanding that repetition and practice are the prerequesites to mastery."

Back at the office, Bill postulates what the three other forms of work are. He considers e-mails, but decides that work may mean at an organizational level, not an individual contributor or manager.

#### Characters

- Eric Reid - latest board member
- Bob Strauss - new company chairman

### Chapter 8 - Monday, September 8

Bill has spent the weekend working on his proposal to Steve to acquire more people-power. When he reaches Steve's office, he finds that his time is being sapped by Sarah, who is chatting Steve up and making commitments about Phoenix project before it's even off the ground.

A short, terse meeting ends with Bill being disappointed. Steve will not allocate any additional funds to Bill, and if anything there may be layoffs in the department soon. If Bill is able to convince other departments to provide him some of their budgets, then he can use that money for new hires, but there will be no new money coming in until the books are balanced. He also will not budge on prioritizing Phoenix or the audits; both are equal in his mind and both need to completed.

The meeting wraps up with Sarah returning and stealing what little time Bill had remaining. Defeated, Bill heads to the change control meeting to find the room wall-to-wall with index cards. There are hundreds of changes pending, and the team starts working on a system to define how those changes are handled. Bill points out the "80/20" rule, "twenty percent of the changes pose eighty percent of the risk." So the team goes through the cards and pull out changes to "fragile" systems, and define them as "**high-risk categories of change that not only must have change requests submitted, but must have authorization before being scheduled.**"

After squaring those away with an emergency plan for each, they decide they will also alert the business units ahead of time about the repercussions of the changes they are requesting and the risk involved, with the intent that it may scare them out of requesting unnecessary changes.

Wes in the meantime hsa been sorting the remaining tasks into two categories, trivial tasks and tasks that need more inspection or knowledge. The first category are defined as "**low-risk changes" or 'standard changes', which are changes that are often performed and can be pre-approved, but should still be tracked**.

The second category becomes the "messy middle changes," where **the "change submitter has responsibility and accountability for consulting and getting approval from people potentially affected." Afterwards, they can submit their change for review and approval for scheduling.

### Chapter 9 - Tuesday, September 9

While Bill is in a budgeting meeting, he gets a `Sev 1` alert and has to leave early, since the credit card processing systems are down. He joins a meeting in the IT department where blame is being shifted around. Bill attempts to narrow down the recent changes, but nobody claims to have made any. Suddenly, Brent says the issue is fixed via speaker phone. Bill is irritated because it meant that somebody made an unauthorized change **and** Brent did the fix without consulting anyone first or recording the solution.

Wes, Patty, and Bill meet up in the change control meeting afterwards, and the team works to prioritize the changes for the current week, since too many are stacked on Friday, which happens to be the same day as the Phoenix launch. Like sailors fleeing a sinking ship, the change requests are moved as far away from the launch of Phoenix as possible. During the meeting, Bill realizes that **"changes are the third category of work**. By changing which days of the week the changes were scheduled for, the team was changing the _work schedule_.

### Chapter 10 - Thursday, September 11

While in a Phoenix meeting, Bill discovers that there are five critical Phoenix tasks assigned to Brent, but he hasn't yet completed them. Frustrated, he heads over to Brent's cubical to find out the reason for the delay. To his dismay, he silently observes Brent fix two issues within the span of five minutes, but neither are related to the all-important Phoenix project.

Bill sits down with Brent and gives him the new rules: Brent is to focus on the Phoenix project only; any requests for Brent to do some task are to go up to his manager Wes. If anyone tries to throw their authority around to coerce Brent or Wes into doing what they want, then they will have to speak to Bill and Steve about it. Bill then instructs Brent to go on "vacation mode" for e-mail and phone for the remainder of the week so he can be 100% focused on the critical Phoenix project.

After, Bill meets with Wes and Patty again to give them the rundown on his Brent decision. The team discusses the fact that Brent seems to magically fix most issues, but has a terrible habit of not writing them down or telling anyone how he did it. Thus, a new set of rules is born; nobody can go to Brent for fixes unless approved by Wes or Bill. And then, once Brent is involved, he's not allowed to solve the issue himself, he has to guide another engineer through the process. Once Brent has been called in to solve an issue, he can no longer be called in again to solve the same issue twice; thus, all issues and fixes should be well documented.

#### Quotes

> Every time that we let Brent fix something that none of us can replicate, Brent gets a little smarter, and the entire system gets dumber. We've got to put an end to that.

### Chapter 11 - Thursday, September 11

Patty calls beel back into the CAB to discuss some concerns she has with the change control system they've implemented  using index cards. She's feeling downtrodden, since only 40% of the changes scheduled have actually been implemented so far. The remaining 60% have some reason they cannot continue, either they couldn't get all the pieces they needed, there was an unforseen techmical error, or, in the majority of cases, they needed Brent (who was unavailable to help after Bill instituted his new rules).

The team discusses whether or not it was a good call to restrict Brent, or whether or not the change control system they've started is even a good decision. After some brief discussion, and some heavy insight by Bill concerning what Eric said to him, the team decides on a new plan:

> "[Bill wants Patty] to get [her] arms around the changes that are heading to Brent, indicating them on the change cards and maybe even requiring this information on all new cards. And to get back to [Bill} when [Patty's team knows] how many changes are Brent-bound, what the changes are, and so forth, along with a sense of what the priorities are."

In essence, because Brent is their bottleneck, they are going to record whether or not a task requires Brent's direct intervention, and will apply this logic to all cards from here on out.

