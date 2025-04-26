====================
MEMBER TASK GROUPING
====================

This is a file that contains tasks/main files for every contirutor *(participant)*.
Every contributor must have his own tasks to avoid conflict pull requests, etc.
If **YOU** want to change a file that under control by other contributor you need to ask him.

And also **every file must have** username of its owner.
Template of owner comment
(if it's possible use multiline-comment, otherwise -- ``#,etc.``)::
  /**
   * contrib-msg
   * Contributor: ${CONTRIBUTOR}
   * Description: ${SHORT_DESCRIPTION}
   */

If you need to check all of this contrib-comments just use command below::

  $ grep -nErA2 'contrib-msg' *

Don't forget to use **shawarmasquad's** methodic of writing a code.

CONTRIBUTORS
^^^^^^^^^^^^

Ivan Koskov
~~~~~~~~~~~

Responsible for:
``include/rendercore.h``

Adisteyf
~~~~~~~~

Responsible for:
``src/main.c,config.def.mk,Makefile``

