// index.js
// Main server code for GitHub App that listens to user's actions
// Maddie Zug & Simon Posada Fishman

const { execFile } = require('child_process')
const bodyParser = require('body-parser')

const TEXT_COMMAND = '../c/matrix_text'
const ANIM_COMMAND = '../c/matrix_anim'
const ANIMATIONS = ['firework', 'meteors', 'storm', 'rainbow-explosion', 'flowers']

let command_queue = []
let contribution_ctr = 0
setTimeout(() => (contribution_ctr = 0), 86400000)

module.exports = app => {
  app.log('Yay, the app was loaded!')

  app.on('installation', async context => {
    const account = context.payload.installation.account
    console.log(account)
    if (account.type == 'Organization') {
      const result = await context.github.orgs.createHook({
        org: account.login,
        name: 'web',
        config: {
          url: process.env.WEBHOOK_PROXY_URL,
          content_type: 'json',
          secret: process.env.WEBHOOK_SECRET,
          events: ['pull_request', 'push']
        }
      })
      console.log(result)
    }
  })

  app.on('push', async context => {
    console.log(context.payload.head_commit.author)

    contribution_ctr += 1

    command_queue.push([ANIM_COMMAND, [ANIMATIONS[Math.floor(Math.random() * ANIMATIONS.length)]]])
    command_queue.push([
      TEXT_COMMAND,
      [context.payload.pusher.name + ' -> ' + context.payload.head_commit.message]
    ])
  })

  const router = app.route('/display')
  router.use(bodyParser.urlencoded({ extended: false }))
  router.get('/', (req, res) => {
    let text = req.query.text
    command_queue.push([TEXT_COMMAND, ['##' + text + '##']])
  })
}

function execute_next() {
  if (command_queue.length > 0) {
    const [command, args] = command_queue.shift()
    execFile(command, args, (error, stdout, stderr) => {
      execute_next()
    })
  } else {
    execFile(TEXT_COMMAND, [`TODAY:${contribution_ctr}`], (error, stdout, stderr) => {
      execute_next()
    })
  }
}

execute_next()
