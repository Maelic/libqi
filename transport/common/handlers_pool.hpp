/*
 * handler_pool.hpp
 *
 *  Created on: Oct 13, 2009 at 2:41:05 PM
 *      Author: Jean-Charles DELAY
 * 			Mail  : jdelay@aldebaran-robotics.com
 */

#ifndef LIBIPPC_HANDLERSPOOL_HPP_
#define LIBIPPC_HANDLERSPOOL_HPP_

#include <list>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <alcommon-ng/transport/common/runnable.hpp>
#include <althread/althreadpool.h>

namespace AL {
  namespace Transport {

class ConnectionHandler;

/**
 * @brief The thread pool used to handler ConnectionHandler(s). It creates
 * five threads, and schedule pushed handlers to those thread.
 */
class HandlersPool {
public:
  /**
   * @brief The HandlersPool constructor.
   */
  HandlersPool ();

  /**
   * @brief The HandlersPool destructor.
   */
  virtual ~HandlersPool ();

public:
  /**
   * @brief Push a handler into the pool and schedule it.
   * @param handler
   */
  void pushTask (boost::shared_ptr<Runnable> handler);

private:
  /**
   * @brief The Boost implementation of the thread pool.
   */
  boost::shared_ptr<AL::ALThreadPool> fPool;
};

}
}
#endif /* !LIBIPPC_HANDLERSPOOL_HPP_ */
