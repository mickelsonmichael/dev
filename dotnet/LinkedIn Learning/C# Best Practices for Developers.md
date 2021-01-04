# C\# Best Practices for Developers

with **Reynald Adolphe**
*Started* January 14, 2010

## Introduction

For this course, you should know the basics of programming principles and C#. Everything in this course will apply to both large team, small team, and individual projects.

You will need to have the Web Development and .NET Core Cross-platform development Workloads installed for Visual Studio.

## 1. Best Practices: An Overview

Best practices give the code a consistent code, making it understandable and facilitating copying, changing, and management.

### When to Use It

According to the instructor, you should use best practices "Most of the time." He claims that it depends on the environment you're working in. If you're working on a project that has a deadline, you might not have time to do a full refactor.

### Getting the Team to Follow

If your team doesn't currently follow the conventions, you can lead the way, and start implementing best practice from the ground up.

Any team that doesn't look at best practices in a good light, may not be a team you want to be on for very long.

## 2. Naming and Handling Classes

You should prefix your projects with the name of your organization, like "Prestige.Biz" or "Prestige.Data."

- Make methods private by default unless needed
- Class names should be meaningful and in PascalCase
- Don't use prefixes or underscores
- Create XML documentation using the `///` formatting
  - This will work with intellisense to show a summary of the methods
- Fields
  - camelCase
  - Private
- Properties
  - PascalCase
  - Access fields
  - Above the methods
- There should be one class per code file

### Constructors

C# will automatically create a default constructor for you when a class has none. So there will always be at least one constructor.

---

I'm stopping here. The course is far too slow-paced for my skill level. There was too much time taken creating classes and methods and explaining basic concepts. I'm probably better off just reading an article on MSDN.
