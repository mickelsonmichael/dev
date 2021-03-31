# The Phoenix Project

I've been reading _The Pheonix Project_ as part of a work book club at Nasdaq. These summaries will be used during the discussion to catch up individuals who didn't get a change to read or for me to review.

## Review

Overall, this book fell off pretty hard. It started really strong, pulling me in with a dramatic and exciting story and likeable characters. But as time went on I found that the more they piled on to the characters the less I seemed to care, and most of the characters ended up losing their new-toy shine. The lessons began to feel like I was being spoonfed, but in the most roundabout way; they almost would have been better off being told by an omnipotent narrator instead of by the "guru" Erik, who served as glorified exposition and a "Superman" character who has no flaws beyond personality traits.

I also found myself becoming irritated with how incorrect the dates in the book became; for a book where every day is important and every chapter starts with the date, it sure does fudge the timeline a lot. For an example, in Chapter 24, John calls Bill on a Saturday and meets him at a bar that night. The next morning, John teslls Bill to prepare for a meeting with Dick "tomorrow" (Monday). The next chapter, 25, then proclaims that the date is "Tuesday, October 14" but starts the first sentence with "The next morning at 7:50am" (which would be a Monday according to the details from the previous chapter). This happends often and is extremely confusing if trying to follow an accurate account as I've done for this summary. For most, this is a seemingly innoculus and likely unnoticable issue, but for me it is a critical flaw in the book. If you are going to attempt to teach me how to do proper processes and documentation, you'd think the least you could do is catch these kinds of timeline issues. With each mistake I find it lowers the credibility of the authors just another notch, in my mind.

Erik was truly inssuferable. As I said, he was a Superman-esque character who could do no wrong, and his only kryptonite appeared to be his affinity for being unusual and rude _on purpose_. The character was unecessary and could have been replaced with multiple characters, an actual factory worker from the plant, or, as I said before, some omiscient narrator guiding us as Bill does online research. It is actually ridiculous to me to think that Bill, a seasoned IT professional, at no point thought to Google the Three Ways or four types of work. Take ten minutes out of your day to look these things up instead of calling Erik who is routinely rude, condescending, and vague.

I'd also like to rip on the John storyline for a moment, which was the least believable part of the plot. I realize that this is a narrative and that I should take the scenarios with a big fictional grain of salt, but if I'm going to apply these practices in my real life, I feel the book owes me a small semblence of realism. If anybody went through what John went through in the story, I would have serious concerns about their health and mental state. Instead, characters routinely make jokes, wagers, and shrug off his obvious downward spiral. At no point does Bill reach out to him, even an HR representative, to make sure he's OK after he witnesses the things he sees in the Audit findings meeting.

While this review seems scathing and seems to suggest you shouldn't read the book, it's actually just a venting session. Overall I think the book was good. Four out of five stars for sure, potentially three depending on how much caffeine I have in my system. It has valuable lessons and a unique way of describing those lessons. If it had just been a bulleted list of concepts, I likely wouldn't have engaged with the content nearly enough. This leads me to believe that it is a superb primer to _The DevOps Handbook_ because I am already interested to read the concepts in more detail, and it give me a good example to utilize when discussing the concepts. So yes, while it isn't the perfect book, it certainly deserves a good amount of praise and all the clout it has garnered over the years.

# Summaries

## Part 1

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
  - "...helps us understand how to create fast flow of work as it moves from Development into IT Operations"
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

### Chapter 12 - Friday, September 12

- The Phoenix Project is set to release today
- No one can get all of the Phoenix code running in the test environment
- Critical issues were coming back from Ops, but most developers had already gone home and needed to be called back in
- Develops continually send the Ops team incomplete releases missing major files
- It takes the QA team three and a half hours to get the code set up and run a smoke test; in that time more issues have already come in
  - Smoke Test - "if you turn the circuit board on and no smoke comes out, it'll probably work"
  - QA has yet to even make it through the smoke test
  - Version control has gone out the window and nobody knows which version the team is currently on
  - Sometimes developers will send over a single file instead of the entire package
- Bill sends an email out to Steve, Chris, and Sarah to delay the deployment
  - The team isn't confident they'll be done with the deployment by 8am the next morning when stores open
  - Steve says they don't have a choice; they've already created marketing materials that are releasing
- Even worse, someone turned on database indexing too soon, and the inserts are taking too long with no way to stop
- Performance of the app is bad; memory leaks without even any users
  - The Ops team will need to restart the server every hour just to keep things running
- Some additional servers have been requisitioned from around the company to help fuel Phoenix
  - Ops had virtualization in place to fix issues like this, but the Devs blamed the issues on virtualization so they had to switch back to old-school servers
- The Ops team will have to manually edit the database to fix some issues, because the software that would help them do it is useless
- The next morning, all POS systems are down because of the database indexing, but Phoenix is up and running
  - All stores are manually processing payments
  - Customers are complaining the new website is unusable, and it has been losing orders in some cases and in others it double- or triple-charges orders
- The Phoenix site is leaking customer credit card numbers

### Chapter 13 - Monday, September 15

- The Phoenix Phiasco is now front-page news
- Ops team is restarting the Phoenix servers nearly every hour to combat memory issues still
- Bill proposes "code rollouts only twice a day and restricting all cod echanges to those affecting performance"  
  - Sarah of course disagrees but is overruled by the combined agreement of the Ops, Dev, and QA leads
- In the "war room" created to handle the POS issues, John notices that they are storing CVV2 credit card codes which is an auditing failure
  - To make theings worse, auditors are on-site _today_, so John goes to distract the auditors and keep them away from the room 

### Chapter 14 - Tuesday, September 16

- Monday night the team managed to stabilize the POS issues with a temporary fix
- The upper management team are waiting turns to see Steve
- Bill rebuffs Steve's blame pointing out that he's warned Steve countless times it would be a disaster
- Steve reveals that the board is considering splitting up the company and is worth more sold in pieces
- He also says that he is going to outsource IT in 90 days if the team can't pull off a miracle
- Chris and Bill meet at a bar and create a tentative friendship; a partnership to prevent all of IT from losing their jobs

### Chapter 15 - Wednesday, September 17

- Finally some good news, the new change process managed to catch an issue before it happened
- Unfortunately, all the changes scheduled after Friday needed to be rescheduled because of Phoenix
- Bill realizes that the fourth category of work is **Unplanned Work**
- Bill then calls Erik to get some more advice after finally realizing all four categories of work
  - **The four categories are (1) Business Projects, (2) Internal Projects, (3) Changes, and (4) Unplanned Work**
  - A critical part of _The First Way_ is to create a visual management of work and pushing work through the system via index cards and a Kanban board
  - Eric reveals that Brent is Bill's constraint and that Bill needs to work to protect Brent (as he is currently doing)
  - Eric mentions a book _The Goal_ by Dr. Eli Goldratt where he explains constraints and bottlenecks. You need to create a system to manage the flow of work to the constraint
  - If you don't improve flow around the constraint, then work piles up because of unplanned work from technical debt
  - Bill's next task is exploit the constraint; make sure that the constraint is never able to waste time
  - After that, step 3 is to "subordinate the constraint" or to limit production to the speed of the constraint. Set the tempo of work according to Brent.

### Chapter 16 - Thursday, September 18

- Another issue; invoices haven't been processed for three days which means the company hasn't been paid
- The team meets in the crisis room and Bill asserts "DO NOT TOUCH ANYTHING WITHOUT GETTING APPROVAL FROM ME"
- After a few hours of work, Patty's team has identified over twenty different potential causes for the failure, which is then further narrowed down to _eight_ potential causes
- An owner is assigned to look into each cause and see if it is the culprit
- Bill returns home confident that the process is in place and that the team will reconvene at 10pm  with updates
- Steve calls Bill directly and begins pressuring him to call Brent in and get him to fix the issue, subverting Bill's new system
- Bill pushes back saying that involving Brent only leads to more issues because it increases the reliance on Brent
- Steve demands that Bill call Brent in to fix the issue, despite Bill saying he disagrees
- Bill gets frustrating with Steve deconstructing his process and resigns right then and there on the phone

-----

## Part 2

### Chapter 17 - Monday, September 22

- Bill is spending his new-found freedom with his son at a trainyard, but is getting calls from his old coworkers
- Bringing in Brent did exactly as Bill predicted and now inventory management systems are down as well
- The team obviously feel abandoned by Bill and want him to return
- Steve finally calls Bill a little later, although Bill dodges the calls until his wife mentions Steve called her directly
- Steve convinces Bill to return, promising not to interfere any more (after a dressing down from Eric)

### Chapter 18 - Tuesday, September 23

- Bill goes to a leadership "off-site" meeting with Steve, Eric, and the rest of the management team
- Steve apologizes direclty to Bill
- Steve also says that it's important for teams to trust each other, so he tells them a story about his life, then asks that the rest of the team do the same

### Chapter 19 - Tuesday, September 23

- Each of IT management team shares personal stories which sparks tears in the room
- Steve then points out that he believes the major flaw is that IT misses every major commitment and schedule they make
- Some blame is pushed towards Chris and the development team, but Chris points out that while the stuff is flawed, they hit their deadlines
- Bill says if that's the case then there's something wrong twith their definition of a completed project
- The deveolopment team never factors in all the work Ops has to do and leaves no time for Ops to work
- The team is way over capacity given the current backlog of work
- The team realizes that John wasn't invited to the meeting and needs to be asked to come in a little late
- Bill points out that the team has entirely too much techincal debt and no time to work it down
- Bill then proposes a project freeze; no new projects into IT until some of the technical debt is wittled down and Phoenix is fixed
- John fights back against the freeze, but Erik tells him that all the safety nets he's put into place (or want to) aren't even necessary
- Steve agrees to a one-week project freeze to see if it makes a difference for Phoenix

### Chapter 20 - Friday, September 26

- Because of the project freeze, the team is actually gaining traction on the Phoenix Project
- Bill, Patty, and Wes are in the CAB discussing the flow of work
- Bill asks how the team determines what work is the priority
- Right now, the highest priority projects are the ones that shout the loudest or bribe the most
- Bill heads outside to call Erik who tells him it's time for another trip to the factory
- Erik asks Bill which work center is his constraint, to which Bill responds "Brent" but that isn't the answer Erik was looking for
- In the factory analogy, Brent isn't a machine that is a bottleneck, he is a person working that machine. But he's required to run most of those machines
- The machine is the **work center** and Brent is the **worker** associated with it
- Work can't be completed on time because Brent can only be at one _work center_ at a time
- Every _work center_ is made up of four things, (1) the machine, (2) the man, (3) the method, and (4) the measures
- Bill has already taken proper steps to standardize Brent's work and reduce reliance on him
- Until they break the reliance on Brent, any future Brents hired will just stand around with nothing to do
- In terms of the project freeze being lifted, the projects that are safe to unfreeze are the ones that _don't require Brent_
- Bill realizes a problem is that he doesn't know which projects require Brent until halfway through them, but Erik leaves him to find out how to determine that on his own
- Bill wants to release a monitoring project, but is unsure whether that's the right move
  - It doesn't require Brent, the goal is to prevent outages (which would involve Brent), and reduce the reliance on Brent for outages that _do_ occur
  - Therefore, it's a good candiate for release, if not the most important
- "...Mike Rother says that it almost doesn't matter what you improve, as long as you're improving something. Why? Because if you aren not improving, entropy gurantees that you are actually geting worse, which ensures that there is no path to zero errors, zero work-related accidents, and zero loss"
- The team needs to get into the habit (_kata_) of doing these improvements
- Erik also introduces the concept of the wait-time ratio
  - `wait time for a resource = % resource busy / % resource idle`
  - If a resource is 50% utilized and 50% idle, then the wait time is 1
  - If a resource is 90% utilized and 10% idle, then the wait time is 9 (9x longer than 1)
  - A critical part of **The Second Way is to make wait times visible** so you know when your work spends days in a queue
  - Lots of works spends most of its lifetime in a queue
- Bill asks about whether John's security issues are a good use of time
  - They don't increase scalability, availability, survivability, sustanability, supportability, **security**, or defensibility of the org
  - Therefore they aren't worth doing at the moment
 
### Chapter 21 - Friday, September 26

- Bill heads over to the meeting with the external auditors
- John looks ill-composed and is under a lot of stress
- Despite the tension in the room, Bill is confident, thanks to Eric, that the company will somehow manage to slip through the audit despite not being prepared
- After five hours, the meeting is concluded with a resounding success
- It turns out there are a large number of downstream, non-IT controls that would catch any issues caused by the inadequate IT systems
- The IT team didn't need the security holes patched because there were teams of individuals responsible for catching any issues they let slip
- John pulls Bill aside to talk, and is distraut that all the time he took doomsaying turned out to be worth nothing
- After yelling at Bill for the disrespect he and the rest of IT have given John over the years, Erik comes back into the room to turn the tables
- Erik yells at John pointing out that the biggest risk to Parts Unlimited isn't losing customer data, it's going out of business
  - If all the security controls put in place grind everything to a hault and force a bankrupcy, then what good were they to the company
  - "You need to protect it in the process that create the work product"

### Chapter 22 - Monday, September 29

- John has disappeared and nobody knows where he went
- Wes, Patty, and Bill meanwhile get together to discuss the new monitoring project and how to conceptulize a "bill of resources and routings"
- After a brief discussion, Patty says she needs time to think about things
- Next Monday (October 6) Patty has created a rough kanban board with three lanes and four rows

|| Ready | Doing | Done |
|-|-|-|-|
| Move worker office ||||
| Add/change/delete account ||||
| Provision new desktop/laptop ||||
| Reset password ||||

- With this Kanban board, Patty has been able to estimate when people are able to get their new laptops (including Bill), and they're currently beating those estimates
- Patty is also creating checklists for setting up laptops to prevent the number of times the laptop has to come back to be properly configured
- She also talks about the "Improvement Kata" that the plants go through; two-week improvement cycles (sprints)
- Later in the day, Patty, Wes, and Bill are discussing how to start releasing work again
- The entire buisness has prioritized the top five projects, which will be the only five projects that will be released immediately after the freeze
- Prioritizing internal projects is proving to be harder
- Bill decides that the highest priority projects are those that increase capacity at the constraint, Brent
- However, if a project doesn't even require Brent, then it should just be done ASAP since it isn't reliant on the constraint
- Two days later (October 8) Patty has delivered Bill's new laptop ahead of schedule

### Chapter 23 - Tuesday, October 7

- Brent is late doing a Phoenix Project task that should have taken him less than an hour
- Turns out its' because the task is spending most of it's time in queues waiting to be worked on
- The team looks back at the wait-time equation

![Wait Time Graph from itrevolution.com](https://user-images.githubusercontent.com/19243212/113167712-382c9300-9201-11eb-97c5-8b7075cb3306.png)

- The team's estimates weren't properly accounting for this wait time when considering how long tasks would take
- Again, they resolve to continue to document and standardize work as it comes in to reduce the time it takes for future work to be completed
- Finally, Patty suggests that they have an "expiditer" who will manage the handoffs until they can get proper Kanbans created for the tasks

### Chapter 24 - Saturday, October 11

- After a relaxing day off, Bill gets an unexpected call from John who has been off the radar for several weeks
- He ignores the call, then proceeds to get 15 more, all from John
- John is drunk and wants to take Bill out for a last drink before he "leaves" (but assures Bill he doesn't mean ending his life)
- Bill heads to the bar and finds that John has packed up a Uhaul and attached it to his car
- John is at a booth and is quite drunk
- Bill tells him some hard truths about how a lot of the work John had required ended up not being necessary, and it very well may be the case that he never contributed anything worthwhile to the company in three years
- After they're done talking, Bill manages to get John into a cab and send him home
- The next day, John has arranged a meeting with the CFO Dick, with a "getting to know you" agenda on Monday morning

### Chapter 25 - Tuesday, October 14

- Bill meets John for their meeting with Dick
- John has shaved his head and is now wearing some new clothes, with no three-ring binder in sight
- John asks Dick about his responsibilities, what a "good day" looks like, and what a "bad day" looks like
- Dick eventually shows him the list of goals he has for the Finance department as CFO
  - Health of company
  - Revenue
  - Market share
  - Average order size
  - Profitability
  - Return on assets
  - Health of Finance
  - Order to cash cycle
  - Accounts receivable
  - Accurate and timely financial reporting
  - Borrowing Costs
- He also shows them a list of important company goals, which he reviews every day
  - Are we competitive?
  - Understanding customer needs and wants: Do we know what to build?
  - Product portfolio: Do we have the right products?
  - R&D effectiveness: Can we build it effectively?
  - Time to market: Can we ship it soon enough to matter?
  - Sales pipeline: Can we convert products to interested prospects?
  - Are we effective?
  - Customer on-time delivery: Are customers getting what we promised them?
  - Customer retention: Are we gaining or losing customers?
  - Sales forcast accuracy: Can we factor this into our sales planning process?
- Finally, Dick also provides them with a spreadsheet that lists the managers held responsible and accountable for these goals
- John and Bill conclude that Dick doesn't realize how much his goals depend on IT
- Bill calls Erik again
  - "Appreciation for the system" suggests you must understand the system that IT operates in
  - IT is partially responsible for many of the goals, but nobody has verbalized that yet (especialy not Dick)
  - There are some IT controls that aren't necessary because other parts of the organization are mitigating those risks already (see audit issues)
  - "you mus tlave the realm of IT to discover where the business relies on IT to achieve its goals"
  - He then gives Bill two new tasks
    1. Find out where IT is under-scoped, where IT actively jeapardizes the goals
    2. Find out where IT is over-scoped, where IT wastes times that don't contribute towards those goals
  - He tells Bill that he and John need to go talk to the people responsible for the goals, find out their roles, what processes work towards those goals, and what jeapordizes them
  - Erik gives the analogy of a shipping company, where trucks have regular oil changes to ensure that breakdowns are reduced

### Chapter 26 - Friday, October 17

- Bill is scheduled to meet with Ron Johnson, VP of Manufacturing Sales
- Ron points out that his team needs forcasting data about what the customers want and they aren't getting it
- Ron also complains about all the outages losing them valueable customers constantly, or causing other customers to rethink their contracts
- Bill and Patty then go see Maggie Lee, the project sponsor for Phoenix
- Much like Ron, Maggie complains about a lack of information about what the customers want
- The main point of both conversations seems to be there's a lack of accurate and timely reporting; having that could really turn the company around

### Chapter 27 - Tuesday, October 27

- Patty, Wes, Chris, John, and Bill are convening about their findings from their meetings
- Bill draws a table listing Dick's performance measures, what systems in IT they rely on, how IT could add risk to those goals, and which IT systems contribute towards them
- See page 265 for the table
- The team creates a list of actionable goals that can help them support the necessary systems
- They take the list of proposals to Dick, who is seemingly upset that they didn't know them before
- Bill proposes that they take three weeks with each of the business leaders to get better defined risks and come up with solutions to "integrate those risks into leading indicators of performance"
- Bill also states flatout that as it is now, Phoenix should never have been approved
- Dick gives his blessing and the team is off
- The group meets up with John again, this time to talk about what John has learned
  - Lots of the controls John put in place weren't necessary thanks to work downstream
  - IT needs to know what downstream controls are in place already so they can spend time worrying about more critical issues
  - He proposes several changes to Security
    1. Reduce the scope of the SOX-404 compliance program, since it is unecessary thanks to downstream protections
    2. Find out how production vulnerabilities got there and prevent them from happening again by modifying the deployment process
    3. Flag all systems in the scope for compliance audits to avoid changes that could jeapordize audits, allowing them to create the ongoing documentation auditors need
  - He also suggests they remove the "cafeteria POS" system and outsource it to a reliable third-party
  - The team agrees that it is important to pay down some more of their technical debt

### Chapter 28 - Monday, October 27

- Project managers are very happy with the new process in place after the freeze
- The backlog has been wittled down and is nearly gone at this point
- Bill is riding high, internally listing all the accomplishments they've managed in a short amount of time
- The wind is taken out of his sails when John calls and sasys that Sarah has been going around the IT freeze by outsourcing
  - She is having a vendor doing some data mining of customer information, which is a breach of Parts Unlimited's Privacy Policy
  - Worse, the vendor uses the same DB tech that the now-removed cafeteria POS system used to use, which is difficult to secure and maintain in production
- "It's Phoenix deployment day" and although the team has only bugfixes, the release still takes all night because of a database inconsitency between the Dev, QA, and Production environments

### Chapter 29 - Monday, November 3

- Steve and the IT team are in the boardroom to meet with Sarah and confront her about her outsourced IT projects
- Unwillingly, she agrees to meet with Bill and Chris regularly to see how they can help with upcoming initiatives
- Once she's gone, the team starts to talk about Phoenix
- Erik states that it's hard to reach targets because they are releasing so infrequently; "you'll never hit the target you're aiming at [with a cannon] if you can fire the cannon only once every nine months"
- The team should continually reduce batch sizes and create a build pipeline to make deployments graually more rapid
- Erik points out the importants of not going in reverse with tasks, only going foward
- The team needs to get Brent into the earliest stages of the development process; he needs to fix the deployments before they even happen
- Bill proposes a new "SWAT team" outside of Phoenix that will create features that will help hit revenue goals as quickly as possible
- The team is allowed to "break whatever rules required to get the job done"
- Initially, the team will focus on customer recommendations to allow marketing to create enticing promotions

-----

## Part 3

### Chapter 30 - Monday, November 3

- Right after the meeting, Bill calls Erik again and the two go to the MRP-8 plant once more
- Erik tells about a scenario where the most popular new product took a long time to create
  - It required two different steps that took a long duration
  - In order to ship enough product to meet demand, the steps had to be done in _huge_ batches
  - The plant found a way to combine the two steps into a single machine
  - This elminated multiple steps and reduce the setup time drastically
- Erik also mentions a talk given by Flickr developers John Allspaw and Paul Hammond
  - Flickr at the time was doing 10 deployments a day
  - The two talked about how QA, Dev, Operations, and the business unit all worked together to create a "super tribe"
  - They ensured that environments were always available, allowing them to rapidly push work through the pipeline, making one-step environment creation and deployment procedure
- He then gives Bill the next objectives
  1. Create a deployment pipeline
  2. Get everything into version control, including everything required to build the environment
  3. Automate the entire environment creation process. A pipeline where you can create environments and deploy code to them on-demand
- These objectives will reduce steup time and eliminate errors

### Chapter 31 - Monday, November 3

- After meeting with Erik, Bill enters the first SWAT team meeting
- He tells the team about Erik's objective to do 10 deploys a day
- There are disagreements about the number of steps it takes to do a deployment between Dev, QA, and Ops; Bill asks each of them to write down all the steps, starting from code committed, to get something deployed
- Before the process even hits Ops, there are over 100 steps between dev and QA
- With the current process they have, two issues keep occuring
  1. Environments aren't available when needed and aren't syncrhonized
  2. Code packaging takes too long and is too error prone because QA has to rely on poor documentation to do it
- Brent and William agree to work on a deployment run book and automate the environment creation process
- William also wants to get packaged code instead of compiled code; he wants something he can deploy immediately to an environment without having to do any packaging work

### Chapter 32 - Monday, November 10

- The team names the SWAT team project _Project Unicorn_
- "[they] started with a clean code bas that was completely decoupled from the Phoenix behemoth"
- To anaylyze the customer data, the team created  a completely new database with data copied from Phoenix, ordery entry, and inventory management systems allowing them to develop and test without impacting the other processes
- Using virtualization, they standardized the operating system, library versions, settings, etc. for creating builds on developer machines
- Again, Sarah takes the wind out of the sales by forcing Brent to fly to Des Moines to help determine how best to split up the company. What's worse is that she did this without teling anyone, including Steve and Bill
- Bill tells Brent to deliberately miss his flights and talks with Steve to instead get one of the other engineers to do Sarah's project instead of Brent

### Chapter 33 - Tuesday, November 11

- _Note: it's veterans day and the man who reminds us that he is a veteran every chapter says nothing about that fact..._
- Project Unicorn reaches an issue because some of their reports take too long to generate
- To get around that, the team utilizes cloud computing mechanisms to run the processes somewhere off-site and not bog-down local resources
- After the sucess of that initiative, Unicorn is now fully running all services, including production, in the cloud
- Unicorn is turning out huge improvements in the company's ability to react to trends, which is leading to a massive spike in sales

### Chapter 34 - Friday, November 28

- Another Severity 1 issue arises on Thanksgiving and the team is assembled
- The traffic to the site is too high and is causing issues, so a developer suggests disabling the automatic recommendations for the time being
- Another fix is to optimize database queries and move large graphics to a third-party CDN
- Beacuse the stocks are selling out too quickly, the team decides on Friday that they need to create a web page for employees to automate the redemption of promo codes when the items aren't in stock at the store but are in stock at the warehouse, as well as a new form on the customer account web page where they can get items delivered directly to them
- Another meeting with Steve and Sarah proves optimistic until Sarah complains that she wants to implement custom-orders
- The team thought it would be possible easily, but it turns out that they would need to rewrite a system that has been outsourced several years ago
- The original plan had been to replace the system but never happened
- The change would take the vendor months to perform, which is far too long a turnaround time
- Instead, Bill suggests a buyout of the contract so they can get their hands back on the application and make the rewrite, and Steve and Dick buy in to the idea

### Chapter 35 - Friday, January 9

- Unicorn is still a star, and Bill is on his way to Steve's house
- Steve sits him down and talks about a promotion to COO after Dick retires
- Erik says some corny stuff about how Bill should write a book called "The DevOps Handbook"
- Eyerolling commences on the reader's part
